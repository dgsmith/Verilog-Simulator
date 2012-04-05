// comment
module test2(a, b, c, x, y, z);
   input a;
   input b;
   input c;
   output x;
   output y;
   output z;
   wire   _a_net0;
   wire   _b_net1;
   wire   c1234;
   wire   d1234;
   
   
   not i0 (_a_net0, a);
   xor _an_inst   (_b_net1, _a_net0, b, c);
   nand d(c1234, _b_net1, a, c);

   nor i100 (d1234, a_net0, b_net1, c1234, c);
   and i10(x, d1234,     c1234,_b_net1);   

   // nand i102(x, d1234, c1234); 
   nand i101(x, d1234,     c1234,_b_net1);   
   or i4 (y, d1234, _a_net0);
   or i5 (z, d1234);
   
endmodule