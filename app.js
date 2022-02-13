var addon = require('bindings')('openCV_project');
const express = require('express');
const fileUpload = require("express-fileupload");
const fs = require("fs");
const path = require("path");

const app = express();
const port = 3000;

app.use(fileUpload());

app.get('/', (req, res) => {
  res.sendFile(path.resolve(__dirname, 'index.html'))
})

app.post('/', (req, res) => {
    const file = req.files.File;
  
  
    var array = addon.getCoords(file.data).split(",").map(Number);

    results = []
    let j = 0;
    for (let i = 0; i < array.length; i += 4){
      results[j] = {
        top_left_x : array[i],
        top_left_y : array[i + 1],
        width : array[i + 2],
        height : array[i + 3],
      }
      j++;
    }
    
    
    res.send(JSON.stringify(results));
  })
  
app.listen(port, () => {
    console.log(`app listening at http://localhost:${port}...`)
})
