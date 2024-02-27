//Available Port
NetAddr.langPort;

///OSC Sender
(
a= NetAddr.new("127.0.0.1", 12345);
a.sendMsg("/hello", "there");
)

///OSC Receiver
(
OSCFunc({|msg, time, addr, recvPort|
	msg.postln; // Print the received message
}, '/fromOF' , recvPort: 57120);
)
