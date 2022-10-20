Uses math;

Const fi='mkseq.inp';
      fo='mkseq.out';

Var n,d:longint;
    res:int64;
    A,Q:array[0..1000000] of int64;

Procedure       doc;
   var i:longint;
   begin
      assign(input,fi);         reset(input);
      assign(output,fo);        rewrite(output);
      readln(n,d);
      for i:=1 to n do read(A[i]);
   end;

Procedure       init;
   var i:longint;
   begin
      Q[0]:=0;
      for i:=1 to n do Q[i]:=Q[i-1]+A[i];
   end;

Procedure       sub1;
   var nn,t:int64;
       i:longint;
   begin
      nn:=0; t:=0; res:=low(int64);
      for i:=1 to n do
      begin
         inc(t,A[i]);
         if t>nn then res:=max(res,t-nn) else nn:=t;
      end;
      write(res);
   end;

Procedure       sub2;
   var k,i,x:longint;
       nn,t:int64;
   begin
      res:=low(int64);
      for k:=0 to 1 do
      begin
         nn:=0; t:=0;
         for i:=1 to (n-k) div d do
         begin
            x:=i*d+k;
            inc(t,Q[x]-Q[x-2]);
            if t>nn then res:=max(res,t-nn) else nn:=t;
         end;
      end;
      write(res);
   end;

Procedure       sub3;
   var k,i,x:longint;
       nn,t:int64;
   begin
      res:=low(int64);
      for k:=0 to d do
      begin
         nn:=0; t:=0;
         for i:=1 to (n-k) div d do
         begin
            x:=i*d+k;
            inc(t,Q[x]-Q[x-d]);
            if t>nn then res:=max(res,t-nn) else nn:=t;
         end;
      end;
      write(res);
   end;

BEGIN
   doc;
   init;
   if d=1 then sub1 else
   if d=2 then sub2 else sub3;
END.
