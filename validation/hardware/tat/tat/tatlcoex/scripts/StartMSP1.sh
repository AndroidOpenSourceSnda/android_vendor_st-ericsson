#!/bin/sh

echo "Start MSP1"

#enable MSP1
sk-ab W 0xD1B 0x87

#reconfigure AB8500
sk-ab W  0x0D69 0x32
sk-ab W  0x0D6a 0xBC
sk-ab W  0x0D6b 0xFF
sk-ab W  0x0D6C 0x10
sk-ab W  0x0D6D 0x1B
sk-ab W  0x0D1B 0x87
sk-ab W  0x0D1C 0x15
sk-ab W  0x0D1D 0x02
sk-ab W  0x0D02 0xAA
sk-ab W 0x0383 0x1e
sk-ab W 0x0D00 0x88

#reconfigure MSP1
sk-db W 0x8015701C 0x00000159
sk-db W 0x8012E0A0 0x000001e
sk-db W 0x80124004 0x000C2300
sk-db W 0x80124030 0x00000021
sk-db W 0x80124008 0x0005203D
sk-db W 0x80124070 0x00000020
sk-db W 0x80124040 0x000000FF

#start MSP1 burst mode
sk-db W 0x80124000 0x000AAAAA
sk-ab W  0x0D1D 0x03

exit
