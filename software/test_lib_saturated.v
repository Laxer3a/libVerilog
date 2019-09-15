module testLibrary(
	input signed [15:0] signedInput,
	input        [15:0] unsignedInput,
	
	output signed [7:0] signedSRange,
	output        [7:0] unsignedSPositive,
	output        [7:0] unsignedUPositive
);

	clampSRange    #(.INW(16),.OUTW(8)) 	myClampSRange	(.valueIn(signedInput)  ,.valueOut(signedSRange));
	clampSPositive #(.INW(16),.OUTW(8))		myClampSPositive(.valueIn(signedInput)  ,.valueOut(unsignedSPositive));
	clampUPositive #(.INW(16),.OUTW(8)) 	myClampUPositive(.valueIn(unsignedInput),.valueOut(unsignedUPositive));

endmodule;
