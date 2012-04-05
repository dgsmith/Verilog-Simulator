// comment
module adder4(a3,a2,a1,a0,b3,b2,b1,b0,s3,s2,s1,s0,c4,c3,c2,c1);
   input a3;
   input a2;
   input a1;
   input a0;
   input b3;
   input b2;
   input b1;
   input b0;
   output s3;
   output s2;
   output s1;
   output s0;
   output c4;
   output   c3;
   output   c2;
   output   c1;
   wire   fa0_x1;
   wire   fa1_x1;
   wire   fa2_x1;
   wire   fa3_x1;
   wire   fa0_c1;
   wire   fa0_c2;
   wire   fa0_c3;
   wire   fa1_c1;
   wire   fa1_c2;
   wire   fa1_c3;
   wire   fa2_c1;
   wire   fa2_c2;
   wire   fa2_c3;
   wire   fa3_c1;
   wire   fa3_c2;
   wire   fa3_c3;
   
   xor #3 i0(s0, a0, b0);
   and #2 i1(c1, a0, b0);
   
   xor #3 i2(fa1_x1, a1, b1);
   xor #3 i3(s1, fa1_x1, c1);
   and #2 i4(fa1_c1, a1, b1);
   and #2 i5(fa1_c2, a1, c1);
   and #2 i6(fa1_c3, b1, c1);
   or  #2 i7(c2, fa1_c1, fa1_c2, fa1_c3);

   xor #3 i8(fa2_x1, a2, b2);
   xor #3 i9(s2, fa2_x1, c2);
   nand #1 i10(fa2_c1, a2, b2);
   nand #1 i11(fa2_c2, a2, c2);
   nand #1 i12(fa2_c3, b2, c2);
   nand #1 i13(c3, fa2_c1, fa2_c2, fa2_c3);

   xor #3 i14(fa3_x1, a3, b3);
   xor #3 i15(s3, fa3_x1, c3);
   and #2 i16(fa3_c1, a3, b3);
   and #2 i17(fa3_c2, a3, c3);
   and #2 i18(fa3_c3, b3, c3);
   or  #2 i19(c4, fa3_c1, fa3_c2, fa3_c3);
endmodule