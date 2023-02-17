/////////////////////////////////////////////////////////
//////////////PLAYING WITH FRAMES IN BUFFER///////////////
//////////////////////////////////////////////////////////
s.boot
b= Buffer.read(s,"E:/Interface/Audio/SuperCollider/AudioSamples/668451__strangehorizon__zephy-people-act.wav");


// Jumping to a random location in the buffer using LFNoise0
{PlayBuf.ar(1, b, 1, LFNoise0.ar(50)*BufFrames.ir(b), loop:1)!2}.play

//Mouse manipulation of frame in buffer
{BufRd.ar(1, b, Lag.ar( K2A.ar( MouseX.kr(0,0.5)) * BufFrames.ir(b), 1))!2}.play

/////////////////////////////////////////////////////////
//////////////SKIPPING THROUGH SAMPLE////////////////////
///// https://scsynth.org/t/rhythmically-skipping-through-a-recording-audio-probing //////////////////////////////////1922/23///////////////////////////////////////////////

~path = "E:/Interface/Audio/SuperCollider/AudioSamples/668451__strangehorizon__zephy-people-act.wav";
f = SoundFile.openRead(~path);
~frames = f.numFrames;
~channels = f.numChannels;
f.close;

s.boot;

b = Array.fill(3, { Buffer.alloc(s, 88200, ~channels) });

(
SynthDef(\segment, { |out, bufnum, rate = 1, time = 1, amp = 0.1|
	var eg = EnvGen.kr(Env.linen(0.01, time, 0.01), doneAction: 2),
	sig = PlayBuf.ar(~channels, bufnum,
		rate * BufRateScale.kr(bufnum));
	Out.ar(out, sig * (eg * amp));
}).add;
)

(
p = Pbind(
	\instrument, \segment,
	\startFrame, Pwhite(0, ~frames - 100000, inf),
	\bufnum, Prout { |ev|
		var playing, releasing, loading, temp;
		#playing, releasing, loading = b;

		// first time through the loop, haven't loaded anything
		// load something, and rest (because 'playing' isn't ready yet)
		loading.read(~path, ev[\startFrame]);
		ev = Rest(playing).yield;

		loop {
			// playing is now the *previous* buffer that was playing
			// playing --> releasing etc.
			temp = playing;
			playing = loading;  // was loading, should play next
			loading = releasing;  // released last time, should load next
			releasing = temp;

			loading.read(~path, ev[\startFrame]);  // to be ready next time

			ev = playing.yield;  // use this buffer as 'bufnum'
		}
	},
	\dur, Pwhite(1, 4, inf) * 0.25,  // rhythmically
	\time, Pfunc { |ev| ev[\dur] / thisThread.clock.tempo },
	\amp, 1
).trace.play;
)

p.stop;

//////////////////////////////////////////////////////////
/////// CUSTOM GRANULAR SYNTH ON BUFFER //////////////////
//////////////////////////////////////////////////////////
s.boot
s.quit
s.stop
b = Buffer.read(s,"E:/Interface/Audio/SuperCollider/AudioSamples/668451__strangehorizon__zephy-people-act.wav");

(
SynthDef(\bufGrain,{ arg out = 0, buffer, rate=1.0, amp = 0.1, dur = 0.1, startPos=0;
	var signal;
	signal = PlayBuf.ar(1, buffer, rate, 1, startPos) * EnvGen.kr(Env.sine(dur, amp)); //doneaction:2
	OffsetOut.ar(out, signal ! 2)
}).add;
)

Synth(\bufGrain, [\buffer, b]); // try it

(
Task({
   1000.do({ arg i;
   		Synth(\bufGrain,
			[\buffer, b,
   			\rate, rrand(0.8, 1.2),
			\amp, rrand(0.05,0.2),
			\dur, rrand(0.00, 0.5),
			\startPos, i*100 // jumping 100 samples per grain
		]);
		0.01.wait;
	});
}).start;
)
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
