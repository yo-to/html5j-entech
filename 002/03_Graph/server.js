var app = require('http').createServer(handler)
  , io = require('socket.io').listen(app)
  , url = require("url")
  , path = require("path")
  , fs = require('fs')

app.listen(8080);

function handler (request, response) {
  var Response = {
    "200":function(file, filename){
      var extname = path.extname(filename);
      var header = {
        "Access-Control-Allow-Origin":"*",
        "Pragma": "no-cache",
        "Cache-Control" : "no-cache"       
      }
      response.writeHead(200, header);
      response.write(file, "binary");
      response.end();
    },
    "404":function(){
      response.writeHead(404, {"Content-Type": "text/plain"});
      response.write("404 Not Found\n");
      response.end();
    },
    "500":function(err){
      response.writeHead(500, {"Content-Type": "text/plain"});
      response.write(err + "\n");
      response.end();
    }
  }

  var uri = url.parse(request.url).pathname
    , filename = path.join(process.cwd(), uri);

  fs.exists(filename, function(exists){
    console.log(filename+" "+exists);
    if (!exists) { Response["404"](); return ; }
    if (fs.statSync(filename).isDirectory()) { filename += '/index.html'; }

    fs.readFile(filename, "binary", function(err, file){
    if (err) { Response["500"](err); return ; }
      Response["200"](file, filename);   
    }); 
  });
}


// ---------------------------------------
io.sockets.on("connection", function (socket) {
	console.log("サーバー：コネクションが確立されました。");
    socket.send("接続を確立しました。");
    
    socket.on('message', function (data) {
      console.log(data);
      socket.broadcast.emit('message', data);
  });
});

io.sockets.on("disconnect", function (socket) {
	console.log("サーバー：コネクションが切断されました。");
});
