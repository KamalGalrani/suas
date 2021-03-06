/****************************************************************************
 *   Copyright (c) 2015 James Wilson. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name ATLFlight nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#include <stdio.h>
#include "dspal_tester.h"
#include "test_utils.h"

int run_io_test_suite(void)
{
   int test_results = TEST_PASS;

   MSG("testing device path access\n");
   test_results |= display_test_results(dspal_tester_spi_test(), "spi loopback test");

   test_results |= display_test_results(dspal_tester_serial_test(), "serial I/O test");

   test_results |= display_test_results(dspal_tester_i2c_test(), "i2c test");

   MSG("testing GPIO\n");
   test_results |= display_test_results(dspal_tester_test_gpio_open_close(), "gpio open/close test");
   test_results |= display_test_results(dspal_tester_test_gpio_ioctl_io(), "gpio ioctl I/O mode test");
   test_results |= display_test_results(dspal_tester_test_gpio_read_write(), "gpio read/write test");
   test_results |= display_test_results(dspal_tester_test_gpio_int(), "gpio INT test");

   MSG("testing file I/O\n");
   test_results |= display_test_results(dspal_tester_test_posix_file_open(), "file open");
   test_results |= display_test_results(dspal_tester_test_posix_file_close(), "file close");
   test_results |= display_test_results(dspal_tester_test_posix_file_read(), "file read");
   test_results |= display_test_results(dspal_tester_test_posix_file_write(), "file write");
   test_results |= display_test_results(dspal_tester_test_posix_file_ioctl(), "file ioctl");
   test_results |= display_test_results(dspal_tester_test_posix_file_remove(), "file remove");
   test_results |= display_test_results(dspal_tester_test_fopen_fclose(), "fopen/fclose test");
   test_results |= display_test_results(dspal_tester_test_fwrite_fread(), "fwrite/fread test");

   return test_results;
}

