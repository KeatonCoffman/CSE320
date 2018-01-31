
/******************************************************************************
  Project #3
Author Keaton Coffman
CSE 320
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;
  Signal ResetA, ResetB;
  Signal Strobe;
  
  // Replace with code to generate four input signals

  circuits( SD("1d-4d"), w, x, y, z, Present, a, b, c, d, e, f, g);

  // Replace with code to display eight output signals
  Pulser ((SD("1a"), "r -- Reset counter"),  ResetA, 'r', 10000);
  Pulser ((SD("2a"), "s -- Strobe counter"), Strobe, 's', 10000);

  Not (SD("1b"), ResetA, ResetB);

  Counter ((SD("1c-2c"), "4-bit counter"), (ResetB, Strobe),(w,x,y,z));

  Probe ( (SD("1e"), "Present"), Present);
  Probe ( (SD("1f"), "a"), a );
  Probe ( (SD("2g"), "b"), b );
  Probe ( (SD("4g"), "c"), c );
  Probe ( (SD("5f"), "d"), d );
  Probe ( (SD("4e"), "e"), e );
  Probe ( (SD("2e"), "f"), f );
  Probe ( (SD("3f"), "g"), g );

}


/******************************************************************************
  Function "circuits" -- implementation of student circuits

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );
  
  Signal notw, notx, noty, notz;
  Signal and1,and2,and3,and4,and5,and6,and7,and8,and9;
  

  // Replace with circuit implementation (Not, And, Or gates)
  Not ( SD(sd,"b1"), w, notw);
  Not ( SD(sd,"b2"), x, notx);
  Not ( SD(sd,"b3"), y, noty);
  Not ( SD(sd,"b4"), z, notz);

  And ( SD(sd,"c1"),(notw,z), and1);
  And ( SD(sd,"c2"),(notx,noty), and2);
  And ( SD(sd,"c3"),(noty,z), and3);
  And ( SD(sd,"c4"),(notx,notz), and4);
  And ( SD(sd,"c5"),(x,noty), and5);
  And ( SD(sd,"c6"),(notw,noty,notz), and6);
  And ( SD(sd,"c7"),(notw,x,z), and7);
  And ( SD(sd,"c8"),(w,notx,notz), and8);
  And ( SD(sd,"c9"),(w,notx,noty), and9);


  Or ( SD(sd,"d1"), (and6,and7, and8, and9), Present);
  Or ( SD(sd,"d2"), (notx,and1), a);
  Or ( SD(sd,"d3"), (y,notz,w), b);
  Or ( SD(sd,"d4"), (One), c);
  Or ( SD(sd,"d5"), (and2,and3), d);
  Or ( SD(sd,"d6"), (and4), e);
  Or ( SD(sd,"d7"), (noty,w), f);
  Or ( SD(sd,"d8"), (w,and5), g);
  
}

