var five = require("johnny-five"),
  board, photoresistor;

board = new five.Board();

board.on("ready", function() {

  photoresistor = new five.Sensor({
    pin: "A0",
    freq: 250
  });

  board.repl.inject({
    pot: photoresistor
  });

  photoresistor.on("data", function() {
    console.log(this.value);
    socket.emit('message', ""+this.value);
  });
});


// ---------------------------------------
var io = require("socket.io-client");
var url = "localhost";
var options = {
    port:8080
};

socket = io.connect(url, options);
socket.on('connect', function (data) {
  console.log("サーバー：コネクションが確立されました。");  
});

socket.on('message', function (msg) {
    console.log("message:",msg);    
});

socket.on('disconnect', function (data) {
  console.log("サーバー：コネクションが切断されました。");  
});
