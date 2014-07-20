package com.stericsson.sdk.signing.cops;

import java.io.File;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.WritableByteChannel;
import java.util.List;

import com.stericsson.sdk.common.memory.IPayloadBlock;
import com.stericsson.sdk.common.memory.MemoryIOException;
import com.stericsson.sdk.signing.ISignerSettings;
import com.stericsson.sdk.signing.a2.A2SignerSettings;
import com.stericsson.sdk.signing.a2.IA2PayloadTypeConstants;
import com.stericsson.sdk.signing.elf.ELFFileHandler;
import com.stericsson.sdk.signing.util.DigestDecorator;

/**
 * @author emicroh
 */
public class ELFSoftwareImagePayload implements ICOPSPayloadWithHashList {

    private ELFFileHandler fileHandler;

    private List<IPayloadBlock> payloadBlocks;

    /**
     * Constructor
     * 
     * @param signerSettings
     *            Signer settings instance
     * @throws IOException
     *             If an I/O related error occurred
     */
    public ELFSoftwareImagePayload(A2SignerSettings signerSettings) throws IOException {
        fileHandler =
            new ELFFileHandler(new File((String) signerSettings.getSignerSetting(ISignerSettings.KEY_INPUT_FILE)));

        int payloadType = (Integer) signerSettings.getSignerSetting(ICOPSSignerSettings.KEY_SW_TYPE);
        if (payloadType == IA2PayloadTypeConstants.TYPE_SW_IMAGE) {
            fileHandler.load(ELFFileHandler.FORMAT_BINARY);
        } else if (payloadType == IA2PayloadTypeConstants.TYPE_ELF) {
            fileHandler.load(ELFFileHandler.FORMAT_ELF);
        }
        payloadBlocks = fileHandler.getPayloadBlocks();
    }

    /**
     * Returns the hash list digested with the specified hash algorithm
     * 
     * @see DigestDecorator#SHA_1
     * @see DigestDecorator#SHA_256
     * @param hashList
     *            COPS hash list to populate
     * @param hashAlgorithm
     *            The hash algorithm (i.e. SHA-1 or SHA-256)
     */
    public void populateHashList(COPSHashList hashList, int hashAlgorithm) {
        DigestDecorator blockHashing = new DigestDecorator(hashAlgorithm);

        try {
            for (IPayloadBlock block : payloadBlocks) {
                blockHashing.update(block.getData());
                byte[] dig = blockHashing.digest();
                DigestDecorator digest = new DigestDecorator(hashAlgorithm);
                digest.update(block.getPositionInfo());
                digest.update(dig);
                hashList.append(digest.digest());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    /**
     * @return Payload destination address
     */
    public long getDestinationAddress() {
        if (payloadBlocks.size() > 0) {
            return ByteBuffer.wrap(payloadBlocks.get(0).getPositionInfo()).getInt(0);
        }

        return 0L;
    }

    /**
     * Calculates and returns the hash value for the payload
     * 
     * @see DigestDecorator#SHA_1
     * @see DigestDecorator#SHA_256
     * @param hashAlgorithm
     *            Algorithm to use for hashing
     * @return Payload hash
     */
    public byte[] getHashValue(int hashAlgorithm) {

        DigestDecorator digester = new DigestDecorator(hashAlgorithm);

        for (IPayloadBlock block : payloadBlocks) {
            try {
                digester.update(block.getData());
            } catch (MemoryIOException e) {
                e.printStackTrace();
                return null;
            }
        }

        return digester.digest();
    }

    /**
     * @return Payload length in number of bytes
     */
    public long getLength() {

        long payloadLength = 0L;

        for (IPayloadBlock block : payloadBlocks) {
            payloadLength = payloadLength + block.getLength();
        }

        return payloadLength;
    }

    /**
     * @param channel
     *            Writable byte channel to write the payload to
     * @throws IOException
     *             If an I/O error occurred.
     */
    public void write(WritableByteChannel channel) throws IOException {
        for (IPayloadBlock block : payloadBlocks) {
            channel.write(ByteBuffer.wrap(block.getPositionInfo()));
            channel.write(ByteBuffer.wrap(block.getData()));
        }
    }

    /**
     * @param fields
     *            TBD
     */
    public void updateCOPSControlFields(COPSControlFields fields) {

    }

}
