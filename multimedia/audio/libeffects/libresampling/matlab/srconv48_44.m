fc=1000;
fs=48000;
T=1/fs;
checkdisto=0;
status = who('maxDelayFast');
if ( size(status) == 0 )
  maxDelayFast = 0;
end

coefcalc48_44;

%*************************** Standard Quality *****************
[shift_34_37 mult_34_37] = scalefilt(deci1_34_37, 34);
figure
freqz((2^shift_34_37)*(mult_34_37/34)*deci1_34_37);zoom on; 
title('frequency response after scaling');

% compute max delay
delay_34_37 = ceil(n_34_37 / 34);
delta=(delay_34_37*34)-n_34_37


totalDelay = delay_34_37;

if( totalDelay > maxDelayFast )
  maxDelayFast = totalDelay
end


%Write the corresponding header file
fid = openfile('table48_44_fasta.h');
fprintf(fid, '#define N_48_44_FASTa %d \n',n_34_37);
fprintf(fid, '#define M_48_44_FASTa %d \n',34);
fprintf(fid, '#define L_48_44_FASTa %d \n',37);
fprintf(fid, '#define decimno_48_44_FASTa %d \n',1);
fprintf(fid, '#define DELAY_48_44_FASTa (%d) \n', delay_34_37);
fprintf(fid, '#define SHIFT_48_44_FASTa (%d) \n' , -shift_34_37);
fprintf(fid, '#define SCALE_48_44_FAST FORMAT_FLOAT(%.15f,MAXVAL) \n' , mult_34_37);
fprintf(fid, 'extern Float const YMEM resample_48_44[%d];\n',(nbcoef_48_44+1));
fprintf(fid, 'extern int const RESAMPLE_MEM src_incr_offset_34_37[%d];\n',incr_off_siz(34,37));
fprintf(fid, '#define NZCOEFS_48_44_FASTa (%d) \n' , nzcoefs);
fclose(fid);

if (define_fidelity==HIFI)
	[shift_34_37H mult_34_37H] = scalefilt(deci1_34_37H, 34);
	figure
	freqz((2^shift_34_37H)*(mult_34_37H/34)*deci1_34_37H);zoom on; 
	title('frequency response after scaling');

	% compute max delay
	delay_34_37H = n_34_37H / 34;
	totalDelay = delay_34_37H;

	if( totalDelay > maxDelayFast )
		maxDelayFast = totalDelay
	end


	%Write the corresponding header file
	fid = openfile('table48_44_fastaH.h');
	fprintf(fid, '#define N_48_44_FASTaH %d \n ',n_34_37H);
	fprintf(fid, '#define M_48_44_FASTaH %d \n ',34);
	fprintf(fid, '#define L_48_44_FASTaH %d \n ',37);
	fprintf(fid, '#define decimno_48_44_FASTaH %d \n ',1);
	fprintf(fid, '#define DELAY_48_44_FASTaH (%d) \n ', delay_34_37H);
	fprintf(fid, '#define SHIFT_48_44_FASTaH (%d) \n' , -shift_34_37H);
	fprintf(fid, '#define SCALE_48_44_FASTH FORMAT_FLOAT(%.15f,MAXVAL) \n' , mult_34_37H);
	fprintf(fid, 'extern Float const YMEM resample_48_44H[%d];\n',(nbcoef_48_44H+1));
	fprintf(fid, 'extern int const RESAMPLE_MEM src_incr_offset_34_37[%d];\n',incr_off_siz(34,37));
	fprintf(fid, '#define NZCOEFS_48_44_FASTaH (%d) \n' , 0);
	fclose(fid);
end
if (checkdisto==0)
    N = 2048;
else
    N=48000;
end

NRES = floor(N*44/48);
		
for i=1:N
	input(i) = 0;
end

PI = atan(1) * 4;
rand('seed',0);

if (checkdisto==0)
    for i=1:N
	    	input(i) = (rand(1) - 0.5);
    end
else
    for i=1:N
          	input(i) = sin(2*pi*fc*T*(i-1))/2;
    end
end

res = upfirdn(input,deci1_34_37,34,37);
res1 = res * 2^(shift_34_37);
res1 = res1 * mult_34_37;
figure
epsilon=1e-10;
fftsiz=1024;
i=1:fftsiz;
freq=(i-1)*fs*(34/37)/fftsiz;
spect=(4/fftsiz)*fft(res(NRES-fftsiz+1:NRES).*chebwin(fftsiz,160)',fftsiz);
spectdb=20*log10(abs(spect)+epsilon);
plot(freq,spectdb);
grid on;
zoom on;
axis([0 fs*34/(37*2) -180 0]);
title('Spectrum of output signal');

if (checkdisto>0)
    fil1=fopen('simout.txt','wt');
    fprintf(fil1,'%f\n',res1);
    fclose('all');
end
%Write the corresponding test file
fid = fopen('testval_hamaca48_44_fasta.c','w');
fprintf(fid,'#ifndef __flexcc2__\n');
fprintf(fid, '#define N_IN  %d \n ',N);
fprintf(fid, '#define N_OUT  %d \n ',NRES);
fprintf(fid,'Float in48_44[%d] = {\n',N);
for k = 1:N-1
     fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL),  \t\t// %d\n',input(k),k-1);
end
k = N;
fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL) }; \t\t// %d\n',input(k),k-1);
fprintf(fid,'const YMEM Float out48_44[%d] = {\n',NRES);
for k = 1:NRES-1
     fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL),  \t\t// %d\n',res1(k),k-1);
end
k = NRES;
fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL) }; \t\t// %d\n',res1(k),k-1);
N=floor(N/16);
NRES=floor(NRES/16);
fprintf(fid,'#else\n');
fprintf(fid, '#define N_IN  %d \n ',N);
fprintf(fid, '#define N_OUT  %d \n ',NRES);
fprintf(fid,'Float in48_44[%d] = {\n',N);
for k = 1:N-1
     fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL),  \t\t// %d\n',input(k),k-1);
end
k = N;
fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL) }; \t\t// %d\n',input(k),k-1);
fprintf(fid,'const YMEM Float out48_44[%d] = {\n',NRES);
for k = 1:NRES-1
     fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL),  \t\t// %d\n',res1(k),k-1);
end
k = NRES;
fprintf(fid,'\tFORMAT_FLOAT(%.15f,MAXVAL) }; \t\t// %d\n',res1(k),k-1);
fprintf(fid,'#endif\n');





fclose(fid);		
