// Get the URL for Web App of the Google App Scripts
function getScriptUrl()
{
	var url = ScriptApp.getService().getUrl();
	return url;
}

/* Get "home page", or a requested page. Expects a 'page' parameter in querystring.
@param {event} e Event passed to doGet, with querystring.
@returns {String/html} Html to be served. */
function doGet(e)
{
	Logger.log(e.parameter.page);
	var pgToLoad = e.parameter.page;

	if (!e.parameter.page)
	{
		Logger.log('!e.parameter.page')
		// When no specific page requested, return "home page"
		return HtmlService.createTemplateFromFile('index').evaluate().setSandboxMode(HtmlService.SandboxMode.IFRAME).addMetaTag('viewport', 'width=device-width, initial-scale=1').setTitle('FKE Smart Parking System');
	}
  
	Logger.log('there is something for the page');
	// Else, use page parameter to pick an html file from the script
	return HtmlService.createTemplateFromFile(pgToLoad).evaluate().setSandboxMode(HtmlService.SandboxMode.IFRAME).addMetaTag('viewport', 'width=device-width, initial-scale=1').setTitle('FKE Smart Parking System');
}

//Linking StyleSheet and JavaScript files
function include (filename)
{
	return HtmlService.createTemplateFromFile(filename).getRawContent();
}

//Get all data from the set range, then return the values in the form of array.
function getSheetsData (range)
{
	var ss = SpreadsheetApp.getActiveSpreadsheet();
	return ss.getRange(range).getValues();
}
 