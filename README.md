# 2-speaker-single-process
Can I use 2 speakers in a single process ?   
=> Yes. But not clear.  
```
device = 0
name = hw:HDA Intel PCH,0
maximum input channels = 2
maximum output channels = 6
Samplerates : 44100 48000 88200 96000 192000 
----------------------------------------------------------
device = 1
name = hw:HDA Intel PCH,1
maximum input channels = 0
maximum output channels = 2
Samplerates : 32000 44100 48000 88200 96000 192000 
----------------------------------------------------------
device = 2
name = hw:HDA Intel PCH,2
maximum input channels = 2
maximum output channels = 0
Samplerates : 44100 48000 88200 96000 176400 192000 
----------------------------------------------------------
device = 3
name = hw:CX20924戙蔐,0
maximum input channels = 2
maximum output channels = 0
Samplerates : 8000 11025 16000 22050 32000 44100 48000 
----------------------------------------------------------
device = 4
name = hw:HDA NVidia,3
maximum input channels = 0
maximum output channels = 8
Samplerates : 32000 44100 48000 88200 96000 176400 192000 
----------------------------------------------------------
device = 5
name = hw:HDA NVidia,7
maximum input channels = 0
maximum output channels = 2
Samplerates : 32000 44100 48000 
----------------------------------------------------------
device = 6
name = hw:HDA NVidia,8
maximum input channels = 0
maximum output channels = 8
Samplerates : 32000 44100 48000 88200 96000 176400 192000 
----------------------------------------------------------
device = 7
name = hw:HDA NVidia,9
maximum input channels = 0
maximum output channels = 8
Samplerates : 32000 44100 48000 88200 96000 176400 192000 
----------------------------------------------------------
device = 8
name = hw:HDA NVidia,3
maximum input channels = 0
maximum output channels = 8
Samplerates : 32000 44100 48000 88200 96000 176400 192000 
----------------------------------------------------------
device = 9
name = hw:HDA NVidia,7
maximum input channels = 0
maximum output channels = 8
Samplerates : 32000 44100 48000 88200 96000 176400 192000 
----------------------------------------------------------
device = 10
name = hw:HDA NVidia,8
maximum input channels = 0
maximum output channels = 8
Samplerates : 32000 44100 48000 88200 96000 176400 192000 
----------------------------------------------------------
device = 11
name = hw:HDA NVidia,9
maximum input channels = 0
maximum output channels = 8
Samplerates : 32000 44100 48000 88200 96000 176400 192000 
----------------------------------------------------------
device = 12
name = hw:JBL Pebbles,0
maximum input channels = 0
maximum output channels = 2
Samplerates : 48000 
----------------------------------------------------------
device = 13
name = default
maximum input channels = 32
maximum output channels = 32
Samplerates : 4000 5512 8000 9600 11025 16000 22050 32000 44100 48000 88200 96000 176400 192000 
----------------------------------------------------------
```
device 0 : analog output speaker    
device 12 : USB output sepeaker   

When I take device 12 for RtOutput. It didn't work. Didn't play through JBE Pebbles.  
Device 0 and device 5(monitor speaker) worked.    

But when I set device 12 as default output and use device 13(defaukt) and device 0.   
Both speaker played simultaneously.  



