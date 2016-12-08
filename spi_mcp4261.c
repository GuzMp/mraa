/*
 * Author: Thomas Ingleby <thomas.c.ingleby@intel.com>
 * Copyright (c) 2014 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "mraa.h"
#include <unistd.h>
#include <stdint.h>

int
main(int argc, char** argv)
{
    mraa_init();
    //! [Interesting]
    printf("MRAA Version: %s\n\n", mraa_get_version() );
   
    mraa_spi_context spi;
    spi = mraa_spi_init(512);
    uint8_t data[] = { 0x03 };
    uint8_t* recv;
    
    mraa_spi_mode(spi, MRAA_SPI_MODE0);
    
    if (spi == NULL) {
        printf("Initialization of spi failed, check syslog for details, exit...\n");
        exit(1);
    }

    printf("SPI initialised successfully\n");
	
    mraa_spi_frequency(spi, 1000);
    //mraa_spi_lsbmode(spi, 0);
    recv = mraa_spi_write_buf(spi, data, 2);
    printf("Writing : %X\n", data[0]);
    printf("RECIVED : %X\n", recv[0]);
     
    //mraa_i2c_stop(spi);
}
