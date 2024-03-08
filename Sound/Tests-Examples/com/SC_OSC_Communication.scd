//retieve the current listening port
NetAddr.langPort; //57120
//create NetAddr
n = NetAddr.new("127.0.0.1", 57120);
//create OSCFunc
o = OSCFunc({argmsg, time, addr,
	recvPort; [msg, time, addr, recvPort].postln;}, '/goodbye', n);

o.free;// remove the OSCFunc when done.

/* RECEIVING OF DATA AND GENERATING SINE WAVE
// Define frequency ranges for each finger
~freqRanges = [
    [20, 800],    // Low range for Finger 1
    [800, 4000],  // Mid range for Finger 2
    [4000, 10000] // High range for Finger 3
];

// Initialize an array to hold our Synth objects
~synths = Array.newClear(~freqRanges.size);

// Function to map normalized touch X position to a frequency range
~mapXtoFreq = { |xNorm, range|
    (xNorm.linlin(0, 1, range[0], range[1])).round(0.01);
};

// Start OSC Server
OSCFunc({ |msg, time, addr, recvPort|
    var func, x, y, id, slot, freq;

    // Parse the OSC message
    slot = msg[1].asInt;  // Assuming the slot number is sent as the first argument
    x = msg[2].asFloat;   // Assuming X position is normalized and sent as the second argument
    y = msg[3].asFloat;   // Assuming Y position is normalized and sent as the third argument (not used here)
    id = msg[4].asInt;    // Assuming tracking ID is sent as the fourth argument (not used here)

    // Map X position to frequency
    freq = ~mapXtoFreq.(x, ~freqRanges[slot]);

    // Check if a Synth for this slot exists, if not, create one
    if(~synths[slot].isNil, {
        ~synths[slot] = Synth.new(\sineWave, [\freq, freq]);
    }, {
        // Update frequency of existing Synth
        ~synths[slot].set(\freq, freq);
    });

}, '/fingers/position').recvPort_(57120); // Listen to OSC messages on port 57120

// Define a simple sine wave SynthDef
SynthDef(\sineWave, { |freq = 440|
    Out.ar(0, SinOsc.ar(freq) * 0.1); // Simple sine wave oscillator with a set frequency
}).add;

// Cleanup function to free synths and OSCFunc when done
~cleanup = {
    ~synths.do(_.free);
    ~synths.clear;
    OSCFunc.clear;
};

*/
