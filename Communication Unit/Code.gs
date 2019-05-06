var ss = SpreadsheetApp.openByUrl(""); //Insert Google Sheets URL
var dateTime = Utilities.formatDate(new Date(), "GMT+8:00", "hh:mm:ss a  d MMMM yyyy");
var row;
var recieveDataMain = ss.getSheetByName(""); //Insert the individual sheet name.

function doGet(e)
{
	Logger.log("--- doGet ---");
	var tag = "",
	value = "";

	try
	{
		if (e == null){e={}; e.parameters = {tag:"test",value:"-1"};}
		tag = e.parameters.tag;
		value = e.parameters.value;
		save_data(tag, value);
		return ContentService.createTextOutput("Wrote:\n  tag: " + tag + "\n  value: " + value);
	} 
	
	catch(error)
	{ 
		Logger.log(error);    
		return ContentService.createTextOutput("oops...." + error.message + "\n" + new Date() + "\ntag: " + tag + "\nvalue: " + value);
	}
}


function save_data(tag, value)
{
	Logger.log("--- save_data ---"); 
	
	//Grab the string data from ESP8266.
	//E.g. "A1V"; "1" means the first parking slot, "V" means vacant ("O" means occupied). 
	try
	{
		if(value=="A1V")
		{
			recieveDataMain.getRange("B2").setValue("Vacant");
			recieveDataMain.getRange("C2").setValue(dateTime);
		}
		
		else if(value=="A1O")
		{
			recieveDataMain.getRange("B2").setValue("Occupied");
			recieveDataMain.getRange("C2").setValue(dateTime);
		}
		
		if(value=="A2V")
		{
			recieveDataMain.getRange("B3").setValue("Vacant");
			recieveDataMain.getRange("C3").setValue(dateTime);
		}
		
		else if(value=="A2O")
		{
			recieveDataMain.getRange("B3").setValue("Occupied");
			recieveDataMain.getRange("C3").setValue(dateTime);
		}
		
		if(value=="A3V")
		{
			recieveDataMain.getRange("B4").setValue("Vacant");
			recieveDataMain.getRange("C4").setValue(dateTime);
		}
    
		else if(value=="A3O")
		{
			recieveDataMain.getRange("B4").setValue("Occupied");
			recieveDataMain.getRange("C4").setValue(dateTime);
		}
		
		if(value=="A4V")
		{
			recieveDataMain.getRange("B5").setValue("Vacant");
			recieveDataMain.getRange("C5").setValue(dateTime);
		}
    
		else if(value=="A4O")
		{
			recieveDataMain.getRange("B5").setValue("Occupied");
			recieveDataMain.getRange("C5").setValue(dateTime);
		}
	}
	
	catch(error)
	{
		Logger.log(JSON.stringify(error));
	}
	
  Logger.log("--- save_data end---"); 
}