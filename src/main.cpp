#include "RtOutput.h"

#define SAMPLERATE 16000

void AudioProbe(){
  /* Audio Probe */
  RtAudio audio;
  unsigned int devices = audio.getDeviceCount();
  RtAudio::DeviceInfo info;
  for (unsigned int i = 0; i < devices; i++) {
    info = audio.getDeviceInfo(i);
    if (info.probed == true) {
      //if (info.inputChannels != 0) {
      if (true) {
        std::cout << "device = " << i << "\n";
        std::cout << "name = " << info.name << "\n";
        std::cout << "maximum input channels = " << info.inputChannels << "\n";
        std::cout << "maximum output channels = " << info.outputChannels << "\n";
        std::cout << "Samplerates : ";
        for (auto sr : info.sampleRates)
          std::cout << sr << " ";
        std::cout << "\n";
        std::cout << "----------------------------------------------------------" << "\n";
      }
    }
  }
}

int main(int argc, char** argv) {
  AudioProbe();
  RtOutput speaker_1(0,1,SAMPLERATE,48000,128,512);
  RtOutput speaker_2(13,1,SAMPLERATE,48000,128,512);

  FILE* fp_1 = fopen(argv[1], "rb");
  FILE* fp_2 = fopen(argv[2], "rb");
  unsigned int nRead_1 = 0;
  unsigned int nRead_2 = 0;

  fseek(fp_1, 0L, SEEK_END);
  nRead_1= ftell(fp_1)-44;  // 44 : WAV format head size
  fseek(fp_1, 44, SEEK_SET);

  fseek(fp_2, 0L, SEEK_END);
  nRead_2= ftell(fp_2)-44;  // 44 : WAV format head size
  fseek(fp_2, 44, SEEK_SET);

  short *buf_1 =  new short[nRead_1/2];
  fread(buf_1,sizeof(short),nRead_1,fp_1);

  short *buf_2 =  new short[nRead_2/2];
  fread(buf_2,sizeof(short),nRead_2,fp_2);

  speaker_1.FullBufLoad(buf_1,nRead_1/2);
  speaker_2.FullBufLoad(buf_2,nRead_2/2);

  speaker_1.Start();
  speaker_2.Start();

  speaker_1.Wait();
  speaker_2.Wait();

  delete[] buf_1;
  delete[] buf_2;
  return 0;
}

