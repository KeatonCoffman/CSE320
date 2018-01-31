
/******************************************************************************
  Project #4
  Author: Keaton Coffman
  September 29, 2016
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  // Replace with code for your Pulsers
  Pulser ((SD("5a"), "Init -- counter"),  Init, 'i', 10000);
  Pulser ((SD("6a"), "Clock -- counter"), Clock, 'c', 10000);

  circuits( SD("3b-6b"), Init, Clock, w, x, y, z );

  // Replace with code for your Probes
  Probe ( (SD("1e"), "w"), w);
  Probe ( (SD("2e"), "x"), x);
  Probe ( (SD("3e"), "y"), y);
  Probe ( (SD("4e"), "z"), z);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );


  // Replace with declarations for any auxiliary Signals
  Signal W,X,Y,Z;
  Signal notw, notx, noty, notz;
  Signal and1,and2,and3,and4,and5,and6;
  

  
  // Replace with code for your DFFs
  Dff("3b",(Init,W,Clock,Zero),w);
  Dff("4b",(Zero,X,Clock,Init),x);
  Dff("5b",(Init,Y,Clock,Zero),y);
  Dff("6b",(Zero,Z,Clock,Init),z);
  
  
  // Replace with circuit implementation (Not, And, Or gates)
  Not ( SD(sd,"b1"), w, notw);
  Not ( SD(sd,"b2"), x, notx);
  Not ( SD(sd,"b3"), y, noty);
  Not ( SD(sd,"b4"), z, notz);

  
  And ( SD(sd,"c1"),(notx,noty), and1);
  And ( SD(sd,"c2"),(x,noty,notz), and2);
  And ( SD(sd,"c4"),(w,z), and3);
  And ( SD(sd,"c6"),(w,noty,notz), and4);
  And ( SD(sd,"c8"),(notw,y),and5);
  And ( SD(sd,"c10"),(x,notz), and6);

  Or ( SD(sd,"d1"), (and1), W);
  Or ( SD(sd,"d2"), (and2,y), X);
  Or ( SD(sd,"d3"), (and2, and3), Y);
  Or ( SD(sd,"d4"), (and5,and6,and4), Z);
}

