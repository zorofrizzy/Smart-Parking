/*


sheet url = https://docs.google.com/spreadsheets/d/1wAKhL1QxzDF_XkHPXO5CZEXFm0XyWIo7lfhIaMduiEs/edit#gid=0

sheet id = 1wAKhL1QxzDF_XkHPXO5CZEXFm0XyWIo7lfhIaMduiEs

Script : https://script.google.com/macros/s/AKfycbxmxN3nbYdzqSSAVhSLNTLYjkqakhcuGb9Tf6WpWGmwbh7rxc8/exec

Script : https://script.google.com/macros/s/AKfycbxmxN3nbYdzqSSAVhSLNTLYjkqakhcuGb9Tf6WpWGmwbh7rxc8/exec?Spot A=1&Spot B=0&Spot C=0&Spot D=1&Spot E=1&Spots Free=2&Total Spots=5

https://script.google.com/macros/s/AKfycbxmxN3nbYdzqSSAVhSLNTLYjkqakhcuGb9Tf6WpWGmwbh7rxc8/exec
https://script.google.com/macros/s/AKfycbxmxN3nbYdzqSSAVhSLNTLYjkqakhcuGb9Tf6WpWGmwbh7rxc8/exec

https://script.google.com/macros/s/AKfycbyAxulUvKUJYC55FWKrzkrBJvK81KfODk5rftzz13oP8WpJi2Hk/exec

Spot A=1&Spot B=0&Spot C=0&Spot D=1&Spot E=1&Spots Free=2&Total Spots=5


https://script.google.com/macros/s/AKfycbyAxulUvKUJYC55FWKrzkrBJvK81KfODk5rftzz13oP8WpJi2Hk/exec?SpotA=1&SpotB=0&SpotC=0&SpotD=1&SpotE=1&SpotsFree=2&TotalSpots=5
*/

function doGet(e) { 
  Logger.log( JSON.stringify(e) );  // view parameters
  var result = 'Ok'; // assume success
  if (e.parameter == 'undefined') {
    result = 'No Parameters';
  }
  else {
    var sheet_id = '1wAKhL1QxzDF_XkHPXO5CZEXFm0XyWIo7lfhIaMduiEs'; 		// Spreadsheet ID
    var sheet = SpreadsheetApp.openById(sheet_id).getActiveSheet();		// get Active sheet
    var newRow = sheet.getLastRow() + 1;						
    var rowData = [];
    rowData[0] = new Date(); 											// Timestamp in column A
    for (var param in e.parameter) {
      Logger.log('In for loop, param=' + param);
      var value = stripQuotes(e.parameter[param]);
      Logger.log(param + ':' + e.parameter[param]);
      switch (param) {
        
        case 'SpotA': //Parameter
          rowData[2] = value; //Value in column B
          result = 'Written on column C';
          break;
        
        case 'SpotB': //Parameter
          rowData[3] = value; //Value in column C
          result += ' ,Written on column D';
          break;
        
        case 'SpotC': //Parameter
          rowData[4] = value; //Value in column C
          result += ' ,Written on column E';
          break;    
        
        case 'SpotD': //Parameter
          rowData[5] = value; //Value in column C
          result += ' ,Written on column F';
          break;
        
        case 'SpotE': //Parameter
          rowData[6] = value; //Value in column C
          result += ' ,Written on column G';
          break;
        
        case 'SpotsFree': //Parameter
          rowData[7] = value; //Value in column C
          result += ' ,Written on column H';
          
        case 'TotalSpots': //Parameter
          rowData[8] = value; //Value in column C
          result += ' ,Written on column I';
          break;
          break;
        default:
          result = "unsupported parameter";
      }
    }
    Logger.log(JSON.stringify(rowData));
    // Write new row below
    var newRange = sheet.getRange(newRow, 1, 1, rowData.length);
    newRange.setValues([rowData]);
  }
  // Return result of operation
  return ContentService.createTextOutput(result);
}
/**
* Remove leading and trailing single or double quotes
*/
function stripQuotes( value ) {
  return value.replace(/^["']|['"]$/g, "");
}
