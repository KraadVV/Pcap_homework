
#include <pcap.h>
#include <stdio.h>
#include <stdint.h>
#include <printfunc.h>
#include <typeanalysis.h>


void usage() {
  printf("syntax: pcap_test <interface>\n");
  printf("sample: pcap_test wlan0\n");
}

//to make code shorter, use function!

void printMac(const u_char *packet)
{
    printf("%x:%x:%x:%x:%x:%x", packet[0],packet[1],packet[2],packet[3],packet[4],packet[5]);
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    usage();
    return -1;
  }

  char* dev = argv[1];
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t* handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "couldn't open device %s: %s\n", dev, errbuf);
    return -1;
  }
    int esc = 1;
  while (esc) {
    struct pcap_pkthdr* header;
    const u_char* packet;

    int res = pcap_next_ex(handle, &header, &packet);


    if (res == 0) continue;
    if (res == -1 || res == -2) break;
//bring typeAnalysis obj
    typeAnalysis ta;
//if using IP and TCP, print it, if not, print err msg and return to start
    if (ta.checkType(&packet[0])==0)
    {
        printf("skipping print sequence \n ========================");
        continue;
    }

//after using it, terminate obj
    ta.~typeAnalysis();
//brinf pf
    printfunc pf;

    pf.print(pf.SOURCE,pf.MAC,&packet[0]);
    pf.print(pf.DESTINATION,pf.MAC,&packet[6]);

    pf.print(pf.SOURCE,pf.IP,&packet[26]);
    pf.print(pf.DESTINATION,pf.IP,&packet[30]);

    pf.print(pf.SOURCE,pf.PORT,&packet[32]);
    pf.print(pf.DESTINATION,pf.PORT,&packet[34]);

    pf.printdata(&packet[0]);

    pf.~printfunc();


  }
  pcap_close(handle);
  return 0;
}
