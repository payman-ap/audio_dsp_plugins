# Stereo to Mono Plugin (lv2)


this is a simple implementation of a ```lv2``` in C to sum the stereo audio and output the summed audio to the left and right channels.

you can compile it on your own machine (of course make changes in the ```Makefile``` and ```.ttl``` files as you need).

Then you can import the plugin in your DAW software (I used it with Carla) and use the Patchbay to route the audio.


One interesting way would be to make a virtual sound card as well. 

for my Linux case it was simply like:


```console
pactl load-module module-null-sink sink_name=CarlaSink sink_properties=device.description=CarlaDSP
```

you can then make the command above executable at start up if you like and for sure you can figure it out for your own need.

