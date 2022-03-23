#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define RTT 4
#define TIMEOUT 4
#define TOT_FRAMES 7
#define sleep
enum {NO,YES}
ACK;
int main()
{
int wait_time,i=1;
ACK=YES; // initially take ACK as YES to send first frame
for(;i<=TOT_FRAMES;)
{
if (ACK==YES && i!=1) // if i is not 1st frame and ACK=YES
{
printf("\nSENDER: ACK for Frame %d Received.\n",i-1);
}
printf("\nSENDER: Frame %d sent, Waiting for ACK...\n",i);
ACK=NO; // after sending i_th frame set ACK=NO
wait_time= rand() % 4+1; //generate random wait time betn 1 to 4
if (wait_time==TIMEOUT)// resend the frame
{
printf("SENDER: ACK not received for Frame %d=>TIMEOUT Resending Frame...",i);
}
else
{
sleep(RTT/2); // wait for RTT/2
printf("\nRECEIVER: Frame %d received,ACK sent\n",i);
printf("--------------------------------------------");
ACK=YES;// set ACK=YES
sleep(RTT/2); // wait for RTT/2
i++; // select next frame
}
}
return 0;
}