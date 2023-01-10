s.boot;
~b0 = Buffer.read(s,"E:/Interface/Audio/PD_patches/piano_10sec.wav");
~b1 = Buffer.read(s,"E:/Interface/Audio/SuperCollider/AudioSamples/668439__ustym-petrovych__timpani-excerpt-1a.wav");

~b0.play;
~b1.play;

// numSamples = numFrames * numChannels

//FRAMES
~b0.numFrames;
~b1.numFrames;

//CHANNELS
~b0.numChannels;
~b1.numChannels;

~b0 = Buffer.readChannel(s, "E:/Interface/Audio/PD_patches/piano_10sec.wav", channels:[0]);

//DURATION
~b0.duration;
~b1.duration;
s.meter;

//BUFFER NUMBER (bufnums)
~b0.bufnum;
~b1.bufnum;

//BUFFER SAMPLE RATE
~b0.sampleRate;
~b1.sampleRate;
s.sampleRate;

//SUMMARY
~b0.query;