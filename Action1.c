Action1()
{
	//Ищем цену первого заказанного билета
	web_reg_save_param_ex(
	"ParamName=FirstPrint",
    "LB=Total Charge: $ ",
    "RB= ",
    "Ordinal=1",
    LAST);
	
	//Количество билетов первого класса
	web_reg_find(
		"Text=First class tickets",
		"SaveCount=FirstClassCount",
		LAST);
	
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
	
	//Вывод на экран нужной нам информации
	lr_output_message(lr_eval_string("Цена первого билета: {FirstPrint}"));
	lr_output_message(lr_eval_string("Количество билетов первого класса: {FirstClassCount}"));


	
	return 0;
}