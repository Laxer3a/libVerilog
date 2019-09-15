/*
--------------------------------------------------------
Test for :
clampSRange    function
clampSPositive function
clampUPositive function

Note: to build this sample, you also need to build the test_lib_saturated.v from the software folder with verilator (copy to the /rtl folder)
--------------------------------------------------------
*/

#include <stdio.h>
#include "../rtl/obj_dir/Vtest_lib_saturated.h"

typedef short			s16;
typedef unsigned short	u16;
typedef char            s8;
typedef unsigned char	u8;

void testFunctions() {
	Vtest_lib_saturated* mod = new Vtest_lib_saturated();
	s16 inputSV;
	u16 inputUV;

	for (int n = 0; n < 65536; n++) {
		inputSV = n;
		inputUV = n;

		mod->signedInput	= inputSV;
		mod->unsignedInput	= inputUV;

		mod->eval();

		s8 outRange = mod->signedSRange;
		u8 outSPos  = mod->unsignedSPositive;
		u8 outUPos	= mod->unsignedUPositive;

		s16 C_range = inputSV;
		if (C_range < -128) { C_range = -128; }
		if (C_range >  127) { C_range =  127; }

		s16 C_Pos   = inputSV;
		if (C_Pos   <    0) { C_Pos =   0; }
		if (C_Pos   >  255) { C_Pos = 255; }

		u16 C_UPos  = inputUV;
		if (C_UPos  > 255) { C_UPos = 255; }
		
		s16 C_RoundT0M1 = inputSV;
		if (C_RoundT0M1 & 1) {
			if (C_RoundT0M1 != -1) {
				if (C_RoundT0M1 > 0) {
					C_RoundT0M1--;
				} else {
					C_RoundT0M1++;
				}
			}
		}

		if (C_range != outRange) {
			printf("error %i\n", n);
		}
		if (C_Pos   != outSPos ) {
			printf("error %i\n", n);
		}
		if (C_UPos  != outUPos ) {
			printf("error %i\n", n);
		}
		if (C_RoundT0M1 != outRound) {
			printf("error %i\n", n);
		}
	}

	delete mod;
}
