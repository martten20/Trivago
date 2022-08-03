#include <SFML/Graphics.hpp>
#include<SFML/Main.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include <iostream>
#include<string>
#include "hotels.h"
using namespace std;
using namespace sf;
hotels hotel;
LinkedList linked;
/////////////////////////////////GUI/////////////////////////////////////////////////////////////
void ADMIN_username();
void ADMIN_page();
void guestpgae();
void addpage();
void updatepage();
void readroom(int n );
void readreservation(int n,int i);
void hotelinformation(string i);
void guestrc();
bool focus(sf::FloatRect sprite, sf::Vector2f mouse_position);

////////////////////////////////////////////////////////////////////////////////////////////////
sf::Vector2f mouse_position;
string userinput_username = "";
string userinput_passowrd = "";
string usernameLog,passowrdlog;
string hotelnameR, hotelnameN, countryN, locationN,number ,numberReservation ,update_numberroooms,dayS,monthS,yearS,dayE,monthE,yearE ,hotelnameupdate ,countrysearch ,day5,month5,year5,hotelnameC ,hotelguestname ,hotelguestcomment ,hotelguestrate;
string rate_str="";





void main()
{

	string mod = "Login";
	sf::RenderWindow welcome_window(sf::VideoMode(1200, 700), "Where");
	sf::Texture background_texture;
	sf::RectangleShape back_pic;
	sf::RectangleShape Guest_Button;
	sf::RectangleShape Admin_Button;
	Texture Guest_Button_wallpaper;
	Texture Admin_button_wallpaper;
	Guest_Button.setSize(sf::Vector2f(200, 100));
	Admin_Button.setSize(sf::Vector2f(200, 100));
	Guest_Button.setPosition(4, 600);
	Admin_Button.setPosition(1000, 600);
	Guest_Button_wallpaper.loadFromFile("guest.png");
	Admin_button_wallpaper.loadFromFile("admin.png");
	Guest_Button.setTexture(&Guest_Button_wallpaper);
	Admin_Button.setTexture(&Admin_button_wallpaper);
	back_pic.setSize(sf::Vector2f(1200.0f, 700.0f));
	background_texture.loadFromFile("Wallpaper.png");
	if (!background_texture.loadFromFile("Wallpaper.png")) {
		cout << "error while loading the background";
	}
	back_pic.setTexture(&background_texture);
	while (welcome_window.isOpen())
	{
		sf::Event event;
		mouse_position.x = sf::Mouse::getPosition(welcome_window).x;
		mouse_position.y = sf::Mouse::getPosition(welcome_window).y;

		while (welcome_window.pollEvent(event))
		{
		
			if (focus(Admin_Button.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					welcome_window.close();
					ADMIN_username();

				}

			if (focus(Guest_Button.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					welcome_window.close();
						 guestpgae();

				}
			
			if (event.type == sf::Event::Closed)
				welcome_window.close();
		}

		welcome_window.clear();
		welcome_window.draw(back_pic);
		welcome_window.draw(Guest_Button);
		welcome_window.draw(Admin_Button);
		welcome_window.display();
	}
	

	
}
bool focus(sf::FloatRect sprite, sf::Vector2f mouse_position) {
	if (sprite.contains(mouse_position)) {
		return true;
	}
	return false;
}

void ADMIN_username()
{	
	sf::RenderWindow Admin (sf::VideoMode(500, 300), "Where");
	Font use_font;
	use_font.loadFromFile("ArialCE.ttf");

	////////////////////background//////////////
	sf::Texture background_texture;
	sf::RectangleShape back_pic;
	Texture Ok,pass,user;
	RectangleShape ok;
	back_pic.setSize(sf::Vector2f(500.0f, 300.0f));
	background_texture.loadFromFile("213LmLjxcKL .png");
	back_pic.setTexture(&background_texture);
////////////////////////////////////////////////////
	Ok.loadFromFile("ok.png");
	user.loadFromFile("usernamepng.png");
	pass.loadFromFile("password.png");
	Text username_text;
	Text passowrd_text;
	username_text.setCharacterSize(30);
	passowrd_text.setCharacterSize(30);
	username_text.setFillColor(sf::Color::Black);
	passowrd_text.setFillColor(sf::Color::Black);
	username_text.setStyle(Text::Bold);
	passowrd_text.setStyle(Text::Bold);
	username_text.setFont(use_font);
	passowrd_text.setFont(use_font);
	username_text.setPosition(10, 35);
	passowrd_text.setPosition(10, 220);
	ok.setPosition(450, 250);
	ok.setSize(Vector2f(50,50));
	ok.setTexture(&Ok);
	

//////////////////////////////////
	sf::RectangleShape username;
	sf::RectangleShape password;
	password.setTexture(&pass);
	username.setTexture(&user);
	username.setSize(sf::Vector2f(400, 50));
	password.setSize(sf::Vector2f(400, 50));
	username.setPosition(3, 30);
	password.setPosition(3, 210);
	username.setFillColor(Color::White);
	password.setFillColor(Color::White);

//////////////////////////////////
	while (Admin.isOpen())
	{
		sf::Event event;
		mouse_position.x = sf::Mouse::getPosition(Admin).x;
		mouse_position.y = sf::Mouse::getPosition(Admin).y;

		while (Admin.pollEvent(event))
		{		
			
						
							if (focus(username.getGlobalBounds(), mouse_position))
								if (event.type == sf::Event::TextEntered)
								{
									
									if (event.text.unicode < 128 && event.text.unicode != 8)
									{
										userinput_username += event.text.unicode;
										username_text.setString(userinput_username);

									}
									if (event.text.unicode == 8 && userinput_username.size() > 0)
									{
										userinput_username.erase(userinput_username.begin() + userinput_username.size() - 1);
										username_text.setString(userinput_username);
										cout << userinput_username;
									}
								}
								if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
								{
									usernameLog = userinput_username;
									
								}

								if (focus(password.getGlobalBounds(), mouse_position))
									if (event.type == sf::Event::TextEntered)
									{

										if (event.text.unicode < 128 && event.text.unicode != 8)
										{
											userinput_passowrd += event.text.unicode;
											passowrd_text.setString(userinput_passowrd);

										}
										if (event.text.unicode == 8 && userinput_passowrd.size() > 0)
										{
											userinput_passowrd.erase(userinput_passowrd.begin() + userinput_passowrd.size() - 1);
											passowrd_text.setString(userinput_passowrd);
											cout << userinput_passowrd;
										}
									}
								if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
								{
									passowrdlog = userinput_passowrd;

								}
						
							
								if (focus(ok.getGlobalBounds(), mouse_position))
									if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
									{
										if (usernameLog == "admin"&&passowrdlog == "admin")
										{
											Admin.close();
											userinput_username = "";
											userinput_passowrd = "";
											ADMIN_page();
										}
									}
								
								
				if (event.type == sf::Event::Closed)
				Admin.close();

		}
		Admin.clear();
		Admin.draw(back_pic);
		Admin.draw(username);
		Admin.draw(password);
		Admin.draw(username_text);
		Admin.draw(passowrd_text);
		Admin.draw(ok);
		Admin.display();
	}

}
void ADMIN_page()
{

	sf::RenderWindow AdminPage(sf::VideoMode(1200, 900), "Where");
	Font use_font;
	use_font.loadFromFile("ArialCE.ttf");
	bool x = false;
	Text hotelnametext;
	hotelnametext.setCharacterSize(30); 
		hotelnametext.setFillColor(sf::Color::Black);
	hotelnametext.setStyle(Text::Bold);
	hotelnametext.setFont(use_font);
	hotelnametext.setPosition(420, 620);


	RectangleShape bac_pic, home,add,Update,remove,hotelname,done,searchbox;
	Texture pic, homepic,addpic,updatepic,removepic,hotelnamepic,searchpic,donepic;
	addpic.loadFromFile("ADD_button.png");
	updatepic.loadFromFile("update_button.png");
	removepic.loadFromFile("remove.png");
	hotelnamepic.loadFromFile("hotelname.png");
	add.setSize(Vector2f(500, 150));
	Update.setSize(Vector2f(500, 150));
	remove.setSize(Vector2f(500, 150));
	hotelname.setSize(Vector2f(500, 50));
	hotelname.setTexture(&hotelnamepic);
	hotelname.setPosition(400, 620);
	add.setPosition(300, 100);
	Update.setPosition(300, 300);
	remove.setPosition(300, 500);
	add.setFillColor(Color::White);
	Update.setFillColor(Color::White);
	remove.setFillColor(Color::White);
	hotelname.setFillColor(Color::White);
	add.setTexture(&addpic);
	Update.setTexture(&updatepic);
	remove.setTexture(&removepic);
	pic.loadFromFile("wallpaper_admin_page.jpg");
	bac_pic.setSize(Vector2f(1200, 900));
	bac_pic.setTexture(&pic);
	homepic.loadFromFile("home.png");
	home.setSize(Vector2f(50, 50));
	home.setPosition(1100, 5);
	home.setFillColor(Color::Red);
	home.setTexture(&homepic);
	searchbox.setSize(Vector2f(500, 150));
	searchbox.setPosition(300, 700);
	searchpic.loadFromFile("SEEARCHBUTTON.png");
	searchbox.setTexture(&searchpic);
	


	
	donepic.loadFromFile("ok.png");
	done.setSize(Vector2f(60, 50));
	done.setPosition(900, 620);
	done.setTexture(&donepic);
	
	
	while (AdminPage.isOpen())
	{
		sf::Event event;
		mouse_position.x = sf::Mouse::getPosition(AdminPage).x;
		mouse_position.y = sf::Mouse::getPosition(AdminPage).y;
		while (AdminPage.pollEvent(event))
		{
		
			if (focus (add.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					AdminPage.close();
					addpage();
					
				}
			if (focus(searchbox.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					AdminPage.close();
					guestpgae();

				}
			if (focus(Update.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
			{
					AdminPage.close();
					updatepage();
			}
			if (focus(remove.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
			{
					
					x = true;
				
				
			}

			if (focus(hotelname.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						hotelnameR += event.text.unicode;
						hotelnametext.setString(hotelnameR);

					}
					if (event.text.unicode == 8 && hotelnameR.size() > 0)
					{
						hotelnameR.erase(hotelnameR.begin() + hotelnameR.size() - 1);
						hotelnametext.setString(hotelnameR);
						cout << hotelnameR;





					}
				}
			}
			if (focus(done.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					if (hotelnameR != "")
					{
						linked.delete_hash(hotelnameR);

						hotelnameR = "";
					}
					x = false;

				}

			if (focus(home.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
				

					AdminPage.close();
					main();
					
				
				

				}

			if (event.type == sf::Event::Closed)
				AdminPage.close();
		}
		AdminPage.clear();
		AdminPage.draw(bac_pic);
		AdminPage.draw(add);
		AdminPage.draw(Update);
		AdminPage.draw(searchbox);
	
		AdminPage.draw(remove);
		if (x == true)
		{
			AdminPage.draw(hotelname);
			AdminPage.draw(hotelnametext);
			AdminPage.draw(done);
		}
		AdminPage.draw(home);
		AdminPage.display();
	}




}
void guestpgae()
{
	bool displayallbool = false;
	bool durationabc=false;
	bool okbool=false;
	bool special = false;
	bool ok2bool = false;
	bool pob = false;
	bool gyym = false;
	bool freemealss = false;
	sf::RenderWindow guestPage(sf::VideoMode(1200, 700), "where");
	RectangleShape bac_pic,home , name , spacific,duration ,displayall ,ok , ok2, done;
	RectangleShape day, month, year;
	Texture daypic, monthpic, yearoic ,okpic,okpic2;
	RectangleShape arr[6] ,arrdur[6] ,arrsp[6];
	Text arrtext[6],text ,arrdurtext[6],arrsptext[6];
	Texture pic,homepic , namepic, spacificpic, durationpic,displayallpic;
	Text nameText ,daytext,monthtext,yeartext;
	pic.loadFromFile("ratecomment.png");
	bac_pic.setSize(Vector2f(1200, 700));
	bac_pic.setTexture(&pic);
	homepic.loadFromFile("home.png");
	home.setSize(Vector2f(50,50));
	home.setPosition(1100, 5);
	home.setFillColor(Color::Red);
	home.setTexture(&homepic);
	
	Font use_font;
	use_font.loadFromFile("ArialCE.ttf");





	nameText.setCharacterSize(50);
	nameText.setFillColor(sf::Color::Black);
	nameText.setStyle(Text::Bold);
	nameText.setFont(use_font);
	nameText.setPosition(20, 10);

	namepic.loadFromFile("country.png");
	name.setSize(Vector2f(1000, 80));
	name.setPosition(5, 5);
	name.setFillColor(Color::White);
	name.setTexture(&namepic);



	spacificpic.loadFromFile("specificquary.png");
	spacific.setSize(Vector2f(400, 120));
	spacific.setPosition(5, 100);
	spacific.setFillColor(Color::White);
	spacific.setTexture(&spacificpic);


	durationpic.loadFromFile("duration.png");
	duration.setSize(Vector2f(370, 120));
	duration.setPosition(820, 100);
	duration.setFillColor(Color::White);
	duration.setTexture(&durationpic);
	



	displayallpic.loadFromFile("displayAll2.png");
	displayall.setSize(Vector2f(400, 120));
	displayall.setPosition(410, 100);
	displayall.setFillColor(Color::White);
	displayall.setTexture(&displayallpic);


	okpic.loadFromFile("ok.png");
	ok.setSize(Vector2f(50, 50));
	ok.setPosition(1020, 10);
	ok.setTexture(&okpic);

	okpic2.loadFromFile("ok.png");
	ok2.setSize(Vector2f(50, 50));
	ok2.setPosition(1020, 10);
	ok2.setTexture(&okpic2);


	done.setSize(Vector2f(100, 100));
	done.setPosition(1000, 560);
	done.setFillColor(Color::Red);

	//////////////////////////////////////////////

	
	

	/////////////////////////////////////////////



	int size = 0;
	int sizeh=0;
	int sizez = 0;

	RectangleShape pool1, pool2, gym1, gym2, freeMeals1, freeMeals2;
	Texture poolpic1, poolpic2, gympic1, gympic2, freeMealspic1, freeMealspic2;
	while (guestPage.isOpen())
	{
		sf::Event event;
		mouse_position.x = sf::Mouse::getPosition(guestPage).x;
		mouse_position.y = sf::Mouse::getPosition(guestPage).y;
		while (guestPage.pollEvent(event))
		{
			
			if (focus(name.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						countrysearch += event.text.unicode;
						nameText.setString(countrysearch);

					}
					if (event.text.unicode == 8 && countrysearch.size() > 0)
					{
						countrysearch.erase(countrysearch.begin() + countrysearch.size() - 1);
						nameText.setString(countrysearch);







					}
				}


			}
			
			size = linked.caunt[countrysearch].size;
			if (focus(displayall.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					okbool = false;
					ok2bool = false;
					durationabc = false;
					 displayallbool = true;
					 special = false;
					 int y = 66;
					 Node*tmp = linked.caunt[countrysearch].head;
					 for (int i = 0; i < size; i++)
					 {
						
						 cout << linked.caunt[countrysearch].head->value.name;
						 arrtext[i].setCharacterSize(50);
						 arrtext[i].setFillColor(sf::Color::Black);
						 arrtext[i].setStyle(Text::Bold);
						 arrtext[i].setFont(use_font);
						 string x = tmp->value.name;
						 arrtext[i].setString(x);
						 arrtext[i].setPosition(500, 200 + y);
						 y += 70;
						 tmp = tmp->next;
						
					 }
					 int x = 66;
					 for (int i = 0; i < size; i++)
					 {
						 arr[i].setSize(Vector2f(400, 60));
						 arr[i].setPosition(500, 200 + x);
						 arr[i].setFillColor(Color::Transparent);


						 x += 70;

					 }
					 for (int i = 0; i < size; i++)
					 {
						 guestPage.draw(arr[i]);
						 guestPage.draw(arrtext[i]);
					 }
					
				}


			if (focus(spacific.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
				
					 displayallbool = false;
					 durationabc = false;
					 okbool = false;
				
					 special = true;

					pool1.setSize(Vector2f(150, 80));
					pool1.setPosition(5, 220);
					pool1.setFillColor(Color::White);
					poolpic1.loadFromFile("poolOFF.png");
					pool1.setTexture(&poolpic1);


					pool2.setSize(Vector2f(150, 80));
					pool2.setPosition(5, 220);
					pool2.setFillColor(Color::White);
					poolpic2.loadFromFile("poolON.png");
					pool2.setTexture(&poolpic2);




					gym1.setSize(Vector2f(150, 80));
					gym1.setPosition(505, 220);
					gym1.setFillColor(Color::White);
					gympic1.loadFromFile("GYMoff.png");
					gym1.setTexture(&gympic1);


					gym2.setSize(Vector2f(150, 80));
					gym2.setPosition(505, 220);
					gym2.setFillColor(Color::White);
					gympic2.loadFromFile("gymON.png");
					gym2.setTexture(&gympic2);





					freeMeals1.setSize(Vector2f(150, 80));
					freeMeals1.setPosition(1005, 220);
					freeMeals1.setFillColor(Color::White);
					freeMealspic1.loadFromFile("freemealsoff.png");
					freeMeals1.setTexture(&freeMealspic1);


					freeMeals2.setSize(Vector2f(150, 80));
					freeMeals2.setPosition(1005, 220);
					freeMeals2.setFillColor(Color::White);
					freeMealspic2.loadFromFile("freemealsON.png");
					freeMeals2.setTexture(&freeMealspic2);








				}

			
			if (focus(pool1.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{

					pob = true;
					freemealss = false;
					gyym = false;
				}

		

			if (focus(gym1.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					pob = false;
					freemealss = false;
					gyym = true;
					

				}

			if (focus(freeMeals1.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{

					pob =false;
					freemealss = true;
					gyym = false;


				}


			if (focus(done.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					guestrc();
				}


			
			for (int i = 0; i < size; i++)
			{
				if (focus(arr[i].getGlobalBounds(), mouse_position))
					if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
					{
						string h;
						h = arrtext[i].getString();
						hotelinformation(h);

					}

			}


			for (int i = 0; i < sizeh; i++)
			{
				if (focus(arrsp[i].getGlobalBounds(), mouse_position))
					if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
					{
						string h;
						h = arrsptext[i].getString();
						hotelinformation(h);

					}

			}
			
			
		
			if (focus(duration.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					durationabc = true;
					displayallbool = false;
					special = false;
					ok2bool = false;
					okbool = false;
					daypic.loadFromFile("day.png");
					day.setSize(Vector2f(200, 100));
					day.setPosition(5, 250);
					day.setFillColor(Color::White);
					day.setTexture(&daypic);


					monthpic.loadFromFile("month.png");
					month.setSize(Vector2f(200, 100));
					month.setPosition(455, 250);
					month.setFillColor(Color::White);
					month.setTexture(&monthpic);


					yearoic.loadFromFile("year.png");
					year.setSize(Vector2f(200, 100));
					year.setPosition(955, 250);
					year.setFillColor(Color::White);
					year.setTexture(&yearoic);


					daytext.setCharacterSize(40);
					daytext.setFillColor(sf::Color::Black);
					daytext.setStyle(Text::Bold);
					daytext.setFont(use_font);
					daytext.setPosition(10, 250);



					monthtext.setCharacterSize(40);
					monthtext.setFillColor(sf::Color::Black);
					monthtext.setStyle(Text::Bold);
					monthtext.setFont(use_font);
					monthtext.setPosition(465, 250);


					yeartext.setCharacterSize(40);
					yeartext.setFillColor(sf::Color::Black);
					yeartext.setStyle(Text::Bold);
					yeartext.setFont(use_font);
					yeartext.setPosition(965, 250);

		

				}
			
			
			if (focus(day.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						day5 += event.text.unicode;
						daytext.setString(day5);

					}
					if (event.text.unicode == 8 && day5.size() > 0)
					{
						day5.erase(day5.begin() + day5.size() - 1);
						daytext.setString(day5);







					}
				}


			}
			int startday;
			if (day5.length() == 2)
				startday = (day5[0] - 48) * 10 + (day5[1] - 48);
			else
			{
				startday = day5[0] - 48;
			}
			if (focus(month.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						month5 += event.text.unicode;
						monthtext.setString(month5);

					}
					if (event.text.unicode == 8 && month5.size() > 0)
					{
						month5.erase(month5.begin() + month5.size() - 1);
						monthtext.setString(month5);







					}
				}


			}
			int startedmonth;
			if (month5.length() == 2)
				startedmonth = (month5[0] - 48) * 10 + (month5[1] - 48);
			else
			{
				startedmonth = month5[0] - 48;
			}
			
			if (focus(year.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						year5 += event.text.unicode;
						yeartext.setString(year5);

					}
					if (event.text.unicode == 8 && year5.size() > 0)
					{
						year5.erase(year5.begin() + year5.size() - 1);
						yeartext.setString(year5);







					}
				}


			}

			int startyear;
			if (year5.length() == 4)
				startyear = (year5[0] - 48) * 1000 + (year5[1] - 48) * 100 + (year5[2] - 48) * 10 + (year5[3] - 48);
			else
			{
				startyear = year5[0] - 48;
			}

			if (durationabc == true)
			{
				
			if (focus(ok.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
					{
					
					okbool = true;
					ok2bool = false;
					special = false;
					displayallbool= false;
					vector<string> names;
					names = linked.diplay_at_time(linked.caunt[countrysearch], startday, startedmonth, startyear);
					 sizez = names.size();
					int y = 66;
					for (int i = 0; i < sizez; i++)
					{

						arrdurtext[i].setCharacterSize(30);
						arrdurtext[i].setFillColor(sf::Color::Black);
						arrdurtext[i].setStyle(Text::Bold);
						arrdurtext[i].setFont(use_font);
						arrdurtext[i].setString(names[i]);
						arrdurtext[i].setPosition(1000, 300 + y);
						y += 70;

					}











					int x = 66;
					for (int i = 0; i < sizez; i++)
					{
						arrdur[i].setSize(Vector2f(300, 60));
						arrdur[i].setPosition(1000, 300 + x);
						arrdur[i].setFillColor(Color::Transparent);


						x += 70;

					}


					countrysearch = "";

					}



			

			}

		

			for (int i = 0; i < sizez; i++)
			{

				if (durationabc == true)
				{
					if (focus(arrdur[i].getGlobalBounds(), mouse_position))
						if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
						{

							string h;
							if (h != "No Hotels Avilable at this Time")
							{
								h = arrdurtext[i].getString();
								hotelinformation(h);
							}

						}
				}
			}


		



			if (focus(home.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					guestPage.close();
					main();

				}

			if (special == true)
			{
				if (focus(ok2.getGlobalBounds(), mouse_position))
					if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
					{
						ok2bool = true;
						okbool = false;
						durationabc = false;
						displayallbool = false;
						int y = 66;
						vector<string> nam = linked.display_with_query(linked.caunt[countrysearch], pob, gyym, freemealss);
						 sizeh = nam.size();
						for (int i = 0; i < sizeh; i++)
						{

							arrsptext[i].setCharacterSize(50);
							arrsptext[i].setFillColor(sf::Color::Black);
							arrsptext[i].setStyle(Text::Bold);
							arrsptext[i].setFont(use_font);
							arrsptext[i].setString(nam[i]);
							arrsptext[i].setPosition(10, 300 + y);
							y += 70;

						}











						int x = 66;
						for (int i = 0; i < sizeh; i++)
						{
							arrsp[i].setSize(Vector2f(400, 60));
							arrsp[i].setPosition(5, 300 + x);
							arrsp[i].setFillColor(Color::Transparent);


							x += 70;

						}

						countrysearch = "";
					}
				
			}



			if (event.type == sf::Event::Closed)
				guestPage.close();
		}
		guestPage.clear();
		guestPage.draw(bac_pic);
		guestPage.draw(name);
		guestPage.draw(nameText);
		guestPage.draw(home);
		guestPage.draw(spacific);
		guestPage.draw(duration);
		guestPage.draw(displayall);
		if (displayallbool == true)
		{
			for (int i = 0; i < size; i++)
			{
				guestPage.draw(arr[i]);
				guestPage.draw(arrtext[i]);

			}
			
		}
		if (durationabc == true)
		{
			guestPage.draw(day);
			guestPage.draw(month);
			guestPage.draw(year);
			guestPage.draw(daytext);
			guestPage.draw(monthtext);
			guestPage.draw(yeartext);
			guestPage.draw(ok);
		}
		if (okbool == true)
		{
			for (int i = 0; i < sizez; i++)
			{
				guestPage.draw(arrdurtext[i]);
				guestPage.draw(arrdur[i]);
				
			}
	
		}
		if (ok2bool == true)
		{
			for (int i = 0; i < sizeh; i++)
			{
				guestPage.draw(arrsptext[i]);
				guestPage.draw(arrsp[i]);

			}
		}
		if (special == true)
		{
			if (pob == false)
			{
				guestPage.draw(pool1);
			}
			else if (pob == true)
			{
				guestPage.draw(pool2);
			}


			if (gyym == false)
			{
				guestPage.draw(gym1);
			}
			else if (gyym == true)
			{
				guestPage.draw(gym2);
			}

			if (freemealss == false)
			{
				guestPage.draw(freeMeals1);
			}
			else if (freemealss == true)
			{
				guestPage.draw(freeMeals2);
			}
			guestPage.draw(ok2);
		}
		
		guestPage.display();
	}












}
void addpage()
{

	bool mealsb = false, poolb = false, gymb = false;
	/////////////////////////////////////////////////////
	sf::RenderWindow AddPage(sf::VideoMode(1200, 700), "Where");
	sf::Texture background_texture, homepic;
	sf::RectangleShape back_pic, home;
	back_pic.setSize(sf::Vector2f(1200, 700));
	background_texture.loadFromFile("wallpaper_admin_page.jpg.png");
	back_pic.setTexture(&background_texture);
	Text nameText, countryText, locationText, numberRoomsText;
	//////////////////////////////////////////////////////
	Font use_font;
	use_font.loadFromFile("ArialCE.ttf");


	nameText.setCharacterSize(50);
	nameText.setFillColor(sf::Color::Black);
	nameText.setStyle(Text::Bold);
	nameText.setFont(use_font);
	nameText.setPosition(20, 10);


	countryText.setCharacterSize(50);
	countryText.setFillColor(sf::Color::Black);
	countryText.setStyle(Text::Bold);
	countryText.setFont(use_font);
	countryText.setPosition(20, 110);



	locationText.setCharacterSize(50);
	locationText.setFillColor(sf::Color::Black);
	locationText.setStyle(Text::Bold);
	locationText.setFont(use_font);
	locationText.setPosition(20, 220);

	numberRoomsText.setCharacterSize(50);
	numberRoomsText.setFillColor(sf::Color::Black);
	numberRoomsText.setStyle(Text::Bold);
	numberRoomsText.setFont(use_font);
	numberRoomsText.setPosition(710, 530);


	///////////////////////////////////////////////////
	RectangleShape name, country, location, pool1, pool2, gym1, gym2, freeMeals1, freeMeals2, stars, stars1, stars2, stars3, stars4, stars5, x1, x2, x3, x4, x5, NumberOfRooms, done;
	Texture namepic, countrypic, locationpic, poolpic1, poolpic2, gympic1, gympic2, freeMealspic1, freeMealspic2, starspic, starspic1, starspic2, starspic3, starspic4, starspic5, picNumberOfRooms;
	namepic.loadFromFile("hotelname.png");
	countrypic.loadFromFile("country.png");
	locationpic.loadFromFile("location.png");
	name.setSize(Vector2f(1000, 80));
	country.setSize(Vector2f(1000, 80));
	location.setSize(Vector2f(1000, 80));
	name.setPosition(5, 5);
	country.setPosition(5, 110);
	location.setPosition(5, 220);
	name.setFillColor(Color::White);
	country.setFillColor(Color::White);
	location.setFillColor(Color::White);
	name.setTexture(&namepic);
	country.setTexture(&countrypic);
	location.setTexture(&locationpic);


	pool1.setSize(Vector2f(150, 80));
	pool1.setPosition(5, 320);
	pool1.setFillColor(Color::White);
	poolpic1.loadFromFile("poolOFF.png");
	pool1.setTexture(&poolpic1);


	pool2.setSize(Vector2f(150, 80));
	pool2.setPosition(5, 320);
	pool2.setFillColor(Color::White);
	poolpic2.loadFromFile("poolON.png");
	pool2.setTexture(&poolpic2);




	gym1.setSize(Vector2f(150, 80));
	gym1.setPosition(5, 410);
	gym1.setFillColor(Color::White);
	gympic1.loadFromFile("GYMoff.png");
	gym1.setTexture(&gympic1);


	gym2.setSize(Vector2f(150, 80));
	gym2.setPosition(5, 410);
	gym2.setFillColor(Color::White);
	gympic2.loadFromFile("gymON.png");
	gym2.setTexture(&gympic2);





	freeMeals1.setSize(Vector2f(150, 80));
	freeMeals1.setPosition(5, 510);
	freeMeals1.setFillColor(Color::White);
	freeMealspic1.loadFromFile("freemealsoff.png");
	freeMeals1.setTexture(&freeMealspic1);


	freeMeals2.setSize(Vector2f(150, 80));
	freeMeals2.setPosition(5, 510);
	freeMeals2.setFillColor(Color::White);
	freeMealspic2.loadFromFile("freemealsON.png");
	freeMeals2.setTexture(&freeMealspic2);

	NumberOfRooms.setSize(Vector2f(150, 70));
	NumberOfRooms.setPosition(700, 520);
	NumberOfRooms.setFillColor(Color::White);
	picNumberOfRooms.loadFromFile("noofrooms.png");
	NumberOfRooms.setTexture(&picNumberOfRooms);



	int sstar = 0;
	stars.setSize(Vector2f(850, 80));
	stars.setPosition(5, 610);
	stars.setFillColor(Color::White);
	starspic.loadFromFile("0.png");
	stars.setTexture(&starspic);

	stars1.setSize(Vector2f(850, 80));
	stars1.setPosition(5, 610);
	stars1.setFillColor(Color::White);
	starspic1.loadFromFile("1.png");
	stars1.setTexture(&starspic1);

	stars2.setSize(Vector2f(850, 80));
	stars2.setPosition(5, 610);
	stars2.setFillColor(Color::White);
	starspic2.loadFromFile("2.png");
	stars2.setTexture(&starspic2);

	stars3.setSize(Vector2f(850, 80));
	stars3.setPosition(5, 610);
	stars3.setFillColor(Color::White);
	starspic3.loadFromFile("3.png");
	stars3.setTexture(&starspic3);

	stars4.setSize(Vector2f(850, 80));
	stars4.setPosition(5, 610);
	stars4.setFillColor(Color::White);
	starspic4.loadFromFile("4.png");
	stars4.setTexture(&starspic4);

	stars5.setSize(Vector2f(850, 80));
	stars5.setPosition(5, 610);
	stars5.setFillColor(Color::White);
	starspic5.loadFromFile("5.png");
	stars5.setTexture(&starspic5);


	x1.setSize(Vector2f(100, 100));
	x1.setPosition(40, 630);
	x1.setFillColor(Color::Red);

	x2.setSize(Vector2f(100, 100));
	x2.setPosition(190, 630);
	x2.setFillColor(Color::Red);

	x3.setSize(Vector2f(100, 100));
	x3.setPosition(410, 630);
	x3.setFillColor(Color::Red);

	x4.setSize(Vector2f(100, 100));
	x4.setPosition(560, 630);
	x4.setFillColor(Color::Red);


	x5.setSize(Vector2f(100, 100));
	x5.setPosition(750, 630);
	x5.setFillColor(Color::Red);




	done.setSize(Vector2f(150, 150));
	done.setPosition(1000, 560);
	done.setFillColor(Color::Red);

	homepic.loadFromFile("home.png");
	home.setSize(Vector2f(50, 50));
	home.setPosition(1100, 5);
	home.setFillColor(Color::Red);
	home.setTexture(&homepic);


	while (AddPage.isOpen())
	{
		sf::Event event;
		mouse_position.x = sf::Mouse::getPosition(AddPage).x;
		mouse_position.y = sf::Mouse::getPosition(AddPage).y;
		while (AddPage.pollEvent(event))
		{
			////////////////////////string////////////////////////

			if (focus(name.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						hotelnameN += event.text.unicode;
						nameText.setString(hotelnameN);

					}
					if (event.text.unicode == 8 && hotelnameN.size() > 0)
					{
						hotelnameN.erase(hotelnameN.begin() + hotelnameN.size() - 1);
						nameText.setString(hotelnameN);
						
						





					}
				}
				hotel.name = hotelnameN;
			}
			

			if (focus(country.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						countryN += event.text.unicode;
						countryText.setString(countryN);

					}
					if (event.text.unicode == 8 && countryN.size() > 0)
					{
						countryN.erase(countryN.begin() + countryN.size() - 1);
						countryText.setString(countryN);
						cout << countryN;





					}
				}
				hotel.country = countryN;
			}


			if (focus(location.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						locationN += event.text.unicode;
						locationText.setString(locationN);

					}
					if (event.text.unicode == 8 && locationN.size() > 0)
					{
						locationN.erase(locationN.begin() + locationN.size() - 1);
						locationText.setString(locationN);
						cout << locationN;





					}
				}
				hotel.location = locationN;
			}


			/////////////////////////////////////////////////////////////////////////////////////
			////////////////////////////boool//////////////////

			if (focus(pool1.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					poolb = true;
				}

			if (focus(gym1.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					gymb = true;
				}

			if (focus(freeMeals1.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					mealsb = true;
				}
			hotel.pool = poolb;
			hotel.gym = gymb;
			hotel.free_meals = mealsb;
			//////////////////////////////////starsss////////////////////////

			if (focus(x1.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					sstar = 1;
				}


			if (focus(x2.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					sstar = 2;
				}

			if (focus(x3.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					sstar = 3;
				}

			if (focus(x4.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					sstar = 4;
				}

			if (focus(x5.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					sstar = 5;
				}

			hotel.num_stars = sstar;
			

			/////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (focus(NumberOfRooms.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						number += event.text.unicode;
						numberRoomsText.setString(number);

					}
					if (event.text.unicode == 8 && number.size() > 0)
					{
						number.erase(number.begin() + number.size() - 1);
						numberRoomsText.setString(number);
						cout << number;





					}
				}
				
			}
	
			///////////////////////////////////////////////////////////////////////////////////////////////////

			/////////////////////////////////rooms////////////////////////////////////////

		

			if (focus(done.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					if (number != "")
					{
						int Rooms = number[0] - 48;
						hotel.num_rooms = Rooms;
						hotel.rooms = new room[Rooms];
						readroom(Rooms);
					}
					
					
				
				}
			if (focus(home.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					AddPage.close();
					hotelnameN = "";
					countryN = "";
					locationN = "";
					number = "";

					linked.append_hash(hotel);

					linked.caunt[hotel.country].display_all();
					ADMIN_page();




				}
			///////////////////////////////////////////////////////////////////////////////////////////////////////
			if (event.type == sf::Event::Closed)
				AddPage.close();



		}


		AddPage.clear();
		AddPage.draw(back_pic);
		AddPage.draw(name);
		AddPage.draw(country);
		AddPage.draw(location);
		AddPage.draw(nameText);
		AddPage.draw(locationText);
		AddPage.draw(countryText);
		AddPage.draw(NumberOfRooms);
		AddPage.draw(numberRoomsText);
		AddPage.draw(home);
		//AddPage.draw(done);
		if (poolb == false)
		{
			AddPage.draw(pool1);
		}
		else if (poolb == true)
		{
			AddPage.draw(pool2);
		}
		if (gymb == false)
		{
			AddPage.draw(gym1);
		}
		else if (gymb == true)
		{
			AddPage.draw(gym2);
		}
		if (mealsb == false)
		{
			AddPage.draw(freeMeals1);
		}
		else if (mealsb == true)
		{
			AddPage.draw(freeMeals2);
		}
		AddPage.draw(stars);
		if (sstar == 1)
		{
			AddPage.draw(stars1);
		}
		if (sstar == 2)
		{
			AddPage.draw(stars2);
		}
		if (sstar == 3)
		{
			AddPage.draw(stars3);
		}
		if (sstar == 4)
		{
			AddPage.draw(stars4);
		}
		if (sstar == 5)
		{
			AddPage.draw(stars5);
		}


		AddPage.display();






	}


}

void readroom(int n)
{
	
	int count;
	Text numberR;
	Font use_font;
	use_font.loadFromFile("ArialCE.ttf");
	RectangleShape wallpaper,wifi, wifi2, tv,tv2, SD, SD2,counter, ok;
	Texture wifipic, wifipic2, tvpic, tvpic2, SDpic, SDpic2, counterpic,okpic ;
	wallpaper.setSize(Vector2f(300, 600));
	wallpaper.setFillColor(Color::White);


	numberR.setCharacterSize(50);
	numberR.setFillColor(sf::Color::Black);
	numberR.setStyle(Text::Bold);
	numberR.setFont(use_font);
	numberR.setPosition(5, 490);
	
	wifipic.loadFromFile("WIFIOF.png");
	wifi.setSize(Vector2f(320, 100));
	wifi.setPosition(5, 40);
	wifi.setFillColor(Color::White);
	wifi.setTexture(&wifipic);

	wifipic2.loadFromFile("WIFION.png");
	wifi2.setSize(Vector2f(320, 100));
	wifi2.setPosition(5, 40);
	wifi2.setFillColor(Color::White);
	wifi2.setTexture(&wifipic2);



	tvpic.loadFromFile("TV.png");
	tv.setSize(Vector2f(320, 100));
	tv.setPosition(5, 180);
	tv.setFillColor(Color::White);
	tv.setTexture(&tvpic);


	tvpic2.loadFromFile("TVON.png");
	tv2.setSize(Vector2f(320, 100));
	tv2.setPosition(5, 180);
	tv2.setFillColor(Color::White);
	tv2.setTexture(&tvpic2);




	SDpic.loadFromFile("SINGLE.png");
	SD.setSize(Vector2f(320, 100));
	SD.setPosition(5, 320);
	SD.setFillColor(Color::White);
	SD.setTexture(&SDpic);




	SDpic2.loadFromFile("DOUBLE.png");
	SD2.setSize(Vector2f(320, 100));
	SD2.setPosition(5, 320);
	SD2.setFillColor(Color::White);
	SD2.setTexture(&SDpic2);

	okpic.loadFromFile("ok.png");
	ok.setSize(Vector2f(60, 60));
	ok.setFillColor(Color::Red);
	ok.setPosition(130, 420);
	ok.setTexture(&okpic);

	

	counterpic.loadFromFile("numberReservation.png");
	counter.setSize(Vector2f(320, 100));
	counter.setPosition(5, 490);
	counter.setFillColor(Color::White);
	counter.setTexture(&counterpic);
	

	for (int i = 0; i < n ; i++)
	{
		bool wi = false, t = false, sd = false;
		sf::RenderWindow room(sf::VideoMode(300, 600), "Room");
		while (room.isOpen())
		{
			mouse_position.x = sf::Mouse::getPosition(room).x;
			mouse_position.y = sf::Mouse::getPosition(room).y;
			Event event;

			while (room.pollEvent(event))
			{

				
				if (focus(wifi.getGlobalBounds(), mouse_position))
					if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
					{


						wi = true;
			


					}
				hotel.rooms[i].wifi = wi;

				if (focus(tv.getGlobalBounds(), mouse_position))
					if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
					{


						t = true;



					}
				hotel.rooms[i].tv = t;
				if (focus(SD.getGlobalBounds(), mouse_position))
					if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
					{


						sd = true;



					}
				hotel.rooms[i].single = sd;


				if (focus(counter.getGlobalBounds(), mouse_position))
						{

						if (event.type == sf::Event::TextEntered)
						{
							if (event.text.unicode < 128 && event.text.unicode != 8)
							{
								numberReservation += event.text.unicode;
								numberR.setString(numberReservation);

							}
							if (event.text.unicode == 8 && numberReservation.size() > 0)
							{
								numberReservation.erase(numberReservation.begin() + numberReservation.size() - 1);
								numberR.setString(numberReservation);
								cout << numberReservation;



							

							}
						}
						

						

					}

		
				if (focus(ok.getGlobalBounds(), mouse_position))
					if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
					{
						count = numberReservation[0] - 48;
						hotel.rooms[i].dur_nam = count;
						hotel.rooms[i].dur = new duration[count];
						 
						readreservation(count,i);



					}


				if (event.type == sf::Event::Closed)
				{
					numberReservation = "";
					room.close();
				}
			}


		

			room.clear();
			room.draw(wallpaper);
		
			if (wi == false)
			{
				room.draw(wifi);
			}
			else if (wi == true)
			{
				room.draw(wifi2);
			}
			if (t == false)
			{
				room.draw(tv);
			}
			else if (t == true)
			{
				room.draw(tv2);
			}
			if (sd == false)
			{
				room.draw(SD);
			}
			else if (sd == true)
			{
				room.draw(SD2);
			}
			room.draw(counter);
			room.draw(numberR);
			room.draw(ok);
		
			room.display();



		}


	}
}

void readreservation(int n,int i)
{
	RectangleShape	wallpaper ,box1,box2,box3,box4,box5,box6 ,ok;
	Texture box1pic, box2pic, box3pic, box4pic, box5pic, box6pic,okpic;
	Font use_font;
	Text SD, SM, SY, ED, EM, EY;
	use_font.loadFromFile("ArialCE.ttf");
	wallpaper.setSize(Vector2f(500, 600));
	wallpaper.setFillColor(Color::White);

	SD.setCharacterSize(50);
	SD.setFillColor(sf::Color::Black);
	SD.setStyle(Text::Bold);
	SD.setFont(use_font);
	SD.setPosition(5, 0);
	
	SM.setCharacterSize(50);
	SM.setFillColor(sf::Color::Black);
	SM.setStyle(Text::Bold);
	SM.setFont(use_font);
	SM.setPosition(5, 82);

	SY.setCharacterSize(50);
	SY.setFillColor(sf::Color::Black);
	SY.setStyle(Text::Bold);
	SY.setFont(use_font);
	SY.setPosition(5, 162);

	ED.setCharacterSize(50);
	ED.setFillColor(sf::Color::Black);
	ED.setStyle(Text::Bold);
	ED.setFont(use_font);
	ED.setPosition(5, 242);

	EM.setCharacterSize(50);
	EM.setFillColor(sf::Color::Black);
	EM.setStyle(Text::Bold);
	EM.setFont(use_font);
	EM.setPosition(5, 322);

	EY.setCharacterSize(50);
	EY.setFillColor(sf::Color::Black);
	EY.setStyle(Text::Bold);
	EY.setFont(use_font);
	EY.setPosition(5, 402);




	box1pic.loadFromFile("startedday.png");
	box1.setSize(Vector2f(500, 80));
	box1.setPosition(0, 0);
	box1.setTexture(&box1pic);


	box2pic.loadFromFile("startedmonth.png");
	box2.setSize(Vector2f(500, 80));
	box2.setPosition(5, 82);
	box2.setTexture(&box2pic);



	box3pic.loadFromFile("startedyear.png");
	box3.setSize(Vector2f(500, 80));
	box3.setPosition(5, 162);
	box3.setTexture(&box3pic);



	box4pic.loadFromFile("enddady.png");
	box4.setSize(Vector2f(500, 80));
	box4.setPosition(5, 242);
	box4.setTexture(&box4pic);



	box5pic.loadFromFile("endmonth.png");
	box5.setSize(Vector2f(500, 80));
	box5.setPosition(5, 322);
	box5.setTexture(&box5pic);




	box6pic.loadFromFile("endyear.png");
	box6.setSize(Vector2f(500, 80));
	box6.setPosition(5, 402);
	box6.setTexture(&box6pic);



	okpic.loadFromFile("ok.png");
	ok.setSize(Vector2f(60, 60));
	ok.setFillColor(Color::Red);
	ok.setPosition(210, 500);
	ok.setTexture(&okpic);












	for (int j = 0; j < n ; j++)
	{
		sf::RenderWindow roomRES(sf::VideoMode(500, 600), "Reservation");
		
		while (roomRES.isOpen())
		{
			mouse_position.x = sf::Mouse::getPosition(roomRES).x;
			mouse_position.y = sf::Mouse::getPosition(roomRES).y;
			Event event;

			while (roomRES.pollEvent(event))
			{


				if (focus(box1.getGlobalBounds(), mouse_position))
				{

					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode < 128 && event.text.unicode != 8)
						{
							dayS += event.text.unicode;
							SD.setString(dayS);

						}
						if (event.text.unicode == 8 && dayS.size() > 0)
						{
							dayS.erase(dayS.begin() + dayS.size() - 1);
							SD.setString(dayS);
							cout << dayS;





						}
					}




				}
				int startday;
				if (dayS.length() == 2)
					startday = (dayS[0] - 48) * 10 + (dayS[1] - 48);
				else
				{
				 startday = dayS[0] - 48;
				}
				hotel.rooms[i].dur[j].day = startday;

				if (focus(box2.getGlobalBounds(), mouse_position))
				{

					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode < 128 && event.text.unicode != 8)
						{
							monthS += event.text.unicode;
							SM.setString(monthS);

						}
						if (event.text.unicode == 8 && monthS.size() > 0)
						{
							monthS.erase(monthS.begin() + monthS.size() - 1);
							SM.setString(monthS);
							cout << monthS;





						}
					}




				}
				int startmonth;
			
				if (monthS.length() == 2)
					startmonth = (monthS[0] - 48) * 10 + (monthS[1] - 48);
				else
				{
					startmonth = monthS[0] - 48;
				}
				hotel.rooms[i].dur[j].month = startmonth;

				if (focus(box3.getGlobalBounds(), mouse_position))
				{

					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode < 128 && event.text.unicode != 8)
						{
							yearS += event.text.unicode;
							SY.setString(yearS);

						}
						if (event.text.unicode == 8 && yearS.size() > 0)
						{
							yearS.erase(yearS.begin() + yearS.size() - 1);
							SY.setString(yearS);
							cout << yearS;





						}
					}




				}
				int startyear;
				if(yearS.length()==4)
				 startyear = (yearS[0] - 48)*1000+(yearS[1]-48)*100+(yearS[2]-48)*10+(yearS[3]-48);
				else
				{
				 startyear = yearS[0] - 48;
				}
				

				hotel.rooms[i].dur[j].year = startyear;

				if (focus(box4.getGlobalBounds(), mouse_position))
				{

					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode < 128 && event.text.unicode != 8)
						{
							dayE += event.text.unicode;
							ED.setString(dayE);

						}
						if (event.text.unicode == 8 && dayE.size() > 0)
						{
							dayE.erase(dayE.begin() + dayE.size() - 1);
							ED.setString(dayE);
							cout << dayE;





						}
					}




				}

				int endday;
				
				if (dayE.length() == 2)
					endday = + (dayE[0] - 48) * 10 + (dayE[1] - 48);
				else
				{
					endday = dayE[0] - 48;
				}
				hotel.rooms[i].dur[j].checkout_day = endday;

				if (focus(box5.getGlobalBounds(), mouse_position))
				{

					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode < 128 && event.text.unicode != 8)
						{
							monthE += event.text.unicode;
							EM.setString(monthE);

						}
						if (event.text.unicode == 8 && monthE.size() > 0)
						{
							monthE.erase(monthE.begin() + monthE.size() - 1);
							EM.setString(monthE);
							cout << monthE;





						}
					}




				}
				int endmonth;
				if (monthE.length() == 2)
					endmonth = (monthE[0] - 48) * 10 + (monthE[1] - 48);
				else
				{
					endmonth = monthE[0] - 48;
				}
			
				hotel.rooms[i].dur[j].checkout_month = endmonth;

				if (focus(box6.getGlobalBounds(), mouse_position))
				{

					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode < 128 && event.text.unicode != 8)
						{
							yearE += event.text.unicode;
							EY.setString(yearE);

						}
						if (event.text.unicode == 8 && yearE.size() > 0)
						{
							yearE.erase(yearE.begin() + yearE.size() - 1);
							EY.setString(yearE);
							cout << yearE;





						}
					}




				}

				int endyear;
				if (yearE.length() == 4)
					endyear = (yearE[0] - 48) * 1000 + (yearE[1] - 48) * 100 + (yearE[2] - 48) * 10 + (yearE[3] - 48);
				else
				{
					endyear = yearE[0] - 48;
				}
				hotel.rooms[i].dur[j].checkout_year = endyear;






				if (focus(ok.getGlobalBounds(), mouse_position))
					if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
					{
						dayS = "";
						monthS = "";
						yearS = "";
						dayE = "";
						monthE = "";
						yearE = "";
						roomRES.close();



					}













				if (event.type == sf::Event::Closed)
					roomRES.close();
			}

			roomRES.clear();
			roomRES.draw(wallpaper);
			roomRES.draw(box1);
			roomRES.draw(box2);
			roomRES.draw(box3);
			roomRES.draw(box4);
			roomRES.draw(box5);
			roomRES.draw(box6);
			roomRES.draw(SD);
			roomRES.draw(SM);
			roomRES.draw(SY);
			roomRES.draw(ED);
			roomRES.draw(EM);
			roomRES.draw(EY);
			roomRES.draw(ok);
			roomRES.display();
		}





	}





	
		


}


void updatepage()
{
	bool mealsb = false, poolb = false, gymb = false, updatestars = false, updaterooms = false;
	sf::RenderWindow update(sf::VideoMode(1200, 700), "Where");
	RectangleShape background, name,   pool1, pool2, gym1, gym2, freeMeals1, freeMeals2, stars, stars1, stars2, stars3, stars4, stars5;
	RectangleShape x1, x2, x3, x4, x5,  home,ok;
	Texture backgroundpic, namepic, noStarspic ,poolpic1, poolpic2, gympic1, gympic2, freeMealspic1, freeMealspic2, starspic, starspic1, starspic2;
	Texture starspic3, starspic4, starspic5, homepic,okpic;
	Text nameText;
	backgroundpic.loadFromFile("wallpaper_admin_page.jpg");
	background.setSize(Vector2f(1200, 700));
	background.setTexture(&backgroundpic);

	Font use_font;
	use_font.loadFromFile("ArialCE.ttf");

	okpic.loadFromFile("ok.png");
	ok.setSize(Vector2f(50, 50));
	ok.setPosition(440, 100);
	ok.setTexture(&okpic);




	pool1.setSize(Vector2f(150, 80));
	pool1.setPosition(5, 320);
	pool1.setFillColor(Color::White);
	poolpic1.loadFromFile("poolOFF.png");
	pool1.setTexture(&poolpic1);


	pool2.setSize(Vector2f(150, 80));
	pool2.setPosition(5, 320);
	pool2.setFillColor(Color::White);
	poolpic2.loadFromFile("poolON.png");
	pool2.setTexture(&poolpic2);




	gym1.setSize(Vector2f(150, 80));
	gym1.setPosition(5, 410);
	gym1.setFillColor(Color::White);
	gympic1.loadFromFile("GYMoff.png");
	gym1.setTexture(&gympic1);


	gym2.setSize(Vector2f(150, 80));
	gym2.setPosition(5, 410);
	gym2.setFillColor(Color::White);
	gympic2.loadFromFile("gymON.png");
	gym2.setTexture(&gympic2);





	freeMeals1.setSize(Vector2f(150, 80));
	freeMeals1.setPosition(5, 510);
	freeMeals1.setFillColor(Color::White);
	freeMealspic1.loadFromFile("freemealsoff.png");
	freeMeals1.setTexture(&freeMealspic1);


	freeMeals2.setSize(Vector2f(150, 80));
	freeMeals2.setPosition(5, 510);
	freeMeals2.setFillColor(Color::White);
	freeMealspic2.loadFromFile("freemealsON.png");
	freeMeals2.setTexture(&freeMealspic2);


	nameText.setCharacterSize(50);
	nameText.setFillColor(sf::Color::Black);
	nameText.setStyle(Text::Bold);
	nameText.setFont(use_font);
	nameText.setPosition(20, 10);





	namepic.loadFromFile("hotelname.png");
	name.setSize(Vector2f(1000, 80));
	name.setPosition(5, 5);
	name.setFillColor(Color::White);
	name.setTexture(&namepic);













	int sstar = 0;
	stars.setSize(Vector2f(850, 80));
	stars.setPosition(5, 610);
	stars.setFillColor(Color::White);
	starspic.loadFromFile("0.png");
	stars.setTexture(&starspic);

	stars1.setSize(Vector2f(850, 80));
	stars1.setPosition(5, 610);
	stars1.setFillColor(Color::White);
	starspic1.loadFromFile("1.png");
	stars1.setTexture(&starspic1);

	stars2.setSize(Vector2f(850, 80));
	stars2.setPosition(5, 610);
	stars2.setFillColor(Color::White);
	starspic2.loadFromFile("2.png");
	stars2.setTexture(&starspic2);

	stars3.setSize(Vector2f(850, 80));
	stars3.setPosition(5, 610);
	stars3.setFillColor(Color::White);
	starspic3.loadFromFile("3.png");
	stars3.setTexture(&starspic3);

	stars4.setSize(Vector2f(850, 80));
	stars4.setPosition(5, 610);
	stars4.setFillColor(Color::White);
	starspic4.loadFromFile("4.png");
	stars4.setTexture(&starspic4);

	stars5.setSize(Vector2f(850, 80));
	stars5.setPosition(5, 610);
	stars5.setFillColor(Color::White);
	starspic5.loadFromFile("5.png");
	stars5.setTexture(&starspic5);


	x1.setSize(Vector2f(100, 100));
	x1.setPosition(40, 630);
	x1.setFillColor(Color::Red);

	x2.setSize(Vector2f(100, 100));
	x2.setPosition(190, 630);
	x2.setFillColor(Color::Red);

	x3.setSize(Vector2f(100, 100));
	x3.setPosition(410, 630);
	x3.setFillColor(Color::Red);

	x4.setSize(Vector2f(100, 100));
	x4.setPosition(560, 630);
	x4.setFillColor(Color::Red);


	x5.setSize(Vector2f(100, 100));
	x5.setPosition(750, 630);
	x5.setFillColor(Color::Red);




	homepic.loadFromFile("home.png");
	home.setSize(Vector2f(50, 50));
	home.setPosition(1100, 5);
	home.setFillColor(Color::Red);
	home.setTexture(&homepic);




	while (update.isOpen())
	{

		Event event;
		mouse_position.x = sf::Mouse::getPosition(update).x;
		mouse_position.y = sf::Mouse::getPosition(update).y;


		while (update.pollEvent(event))
		{

			if (focus(name.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						hotelnameupdate += event.text.unicode;
						nameText.setString(hotelnameupdate);

					}
					if (event.text.unicode == 8 && hotelnameupdate.size() > 0)
					{
						hotelnameupdate.erase(hotelnameupdate.begin() + hotelnameupdate.size() - 1);
						nameText.setString(hotelnameupdate);
						cout << hotelnameupdate;





					}
				}
			}

		

			if (focus(pool1.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					poolb = true;

				}
	
			if (focus(gym1.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					gymb = true;
				}
		
			if (focus(freeMeals1.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					mealsb = true;
				}


		

			if (focus(ok.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					hotelinformation(hotelnameupdate);
				}




			if (focus(x1.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					sstar = 1;

				}


			if (focus(x2.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					sstar = 2;
				}

			if (focus(x3.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					sstar = 3;
				}

			if (focus(x4.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					sstar = 4;
				}

			if (focus(x5.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					sstar = 5;
				}




		








			if (focus(ok.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					hotelinformation(hotelnameupdate);



				}

			if (focus(home.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					if (hotelnameupdate != "")
					{
						string s;
						s = linked.nam[hotelnameupdate].head->value.country;
						Node* tmp = linked.caunt[s].head;
						while (tmp->value.name != hotelnameupdate)
						{
							tmp = tmp->next;
						}


						linked.nam[hotelnameupdate].head->value.pool = poolb;
						tmp->value.pool = poolb;

						linked.nam[hotelnameupdate].head->value.gym = gymb;
						tmp->value.gym = gymb;


						linked.nam[hotelnameupdate].head->value.free_meals = mealsb;
						tmp->value.free_meals = mealsb;




						linked.nam[hotelnameupdate].head->value.num_stars = sstar;
						tmp->value.num_stars = sstar;
						hotelnameupdate = "";
					}
					update.close();
					main();
				}





			if (event.type == sf::Event::Closed)
				update.close();
		}
















		update.clear();

		update.draw(background);
		update.draw(name);
		update.draw(nameText);
		if (poolb == false)
		{
			update.draw(pool1);
		}
		else if (poolb == true)
		{
			update.draw(pool2);
		}
		if (gymb == false)
		{
			update.draw(gym1);
		}
		else if (gymb == true)
		{
			update.draw(gym2);
		}
		if (mealsb == false)
		{
			update.draw(freeMeals1);
		}
		else if (mealsb == true)
		{
			update.draw(freeMeals2);
		}

		update.draw(ok);


		if (sstar == 0)
		{
			update.draw(stars);
		}
		if (sstar == 1)
		{
			update.draw(stars1);
		}
		if (sstar == 2)
		{
			update.draw(stars2);
		}
		if (sstar == 3)
		{
			update.draw(stars3);
		}
		if (sstar == 4)
		{
			update.draw(stars4);
		}
		if (sstar == 5)
		{
			update.draw(stars5);
		}



		update.draw(home);
		update.display();


	}

	}


void hotelinformation(string i)
{
	RectangleShape wallpaper,wallpaper2 ,Name,country, pool1, pool2, gym1, gym2, freeMeals1, freeMeals2, stars1, stars2, stars3, stars4, stars5 , box[5] ,boxrate;
	Texture wallpaperpic, poolpic1, poolpic2, gympic1, gympic2, freeMealspic1,freeMealspic2, starspic1, starspic2, starspic3, starspic4, starspic5;
	Text nametext,countrytext ,boxtext[5],boxrate1;
	
	
	Font use_font;
	use_font.loadFromFile("ArialCE.ttf");
	
	if (i == "Hard Rock")
	{
		wallpaperpic.loadFromFile("Hard Rock - Rio - Brazil.png");
	}
	else if (i == "Hilton")
	{
		wallpaperpic.loadFromFile("Hilton - BH - USA.png");
	}
	else if (i == "Holiday Inn")
	{
		wallpaperpic.loadFromFile("Holiday Inn - CA - USA.png");

	}
	else if (i == "Le Negresco")
	{
		wallpaperpic.loadFromFile("Le Negresco - Nice - France.png");
	}
	else if (i == "Meridien")
	{
		wallpaperpic.loadFromFile("Meridien - Harm - Egypt.png");
	}
	wallpaper2.setSize(Vector2f(500, 500));
	wallpaper2.setPosition(0, 0);
	wallpaper2.setFillColor(Color::White);
	wallpaper.setSize(Vector2f(500, 500));
	wallpaper.setPosition(0, 500);

	wallpaper.setFillColor(Color::White);
	wallpaper.setTexture(&wallpaperpic);


	Name.setSize(Vector2f(300, 50));
	Name.setPosition(5, 5);
	Name.setFillColor(Color::Black);

	country.setSize(Vector2f(300, 50));
	country.setPosition(5, 65);
	country.setFillColor(Color::Black);

	nametext.setCharacterSize(30);
	countrytext.setCharacterSize(30);
	nametext.setFillColor(sf::Color::Black);
	countrytext.setFillColor(sf::Color::Black);
	nametext.setStyle(Text::Bold);
	countrytext.setStyle(Text::Bold);
	nametext.setFont(use_font);
	countrytext.setFont(use_font);
	nametext.setPosition(10, 5);
	countrytext.setPosition(10, 65);


	nametext.setString(linked.nam[i].head->value.name);
	countrytext.setString(linked.nam[i].head->value.country);





	pool1.setSize(Vector2f(150, 80));
	pool1.setPosition(5, 155);
	pool1.setFillColor(Color::White);
	poolpic1.loadFromFile("poolOFF.png");
	pool1.setTexture(&poolpic1);


	pool2.setSize(Vector2f(150, 80));
	pool2.setPosition(5, 155);
	pool2.setFillColor(Color::White);
	poolpic2.loadFromFile("poolON.png");
	pool2.setTexture(&poolpic2);


	gym1.setSize(Vector2f(150, 80));
	gym1.setPosition(5, 245);
	gym1.setFillColor(Color::White);
	gympic1.loadFromFile("GYMoff.png");
	gym1.setTexture(&gympic1);


	gym2.setSize(Vector2f(150, 80));
	gym2.setPosition(5, 245);
	gym2.setFillColor(Color::White);
	gympic2.loadFromFile("gymON.png");
	gym2.setTexture(&gympic2);


	freeMeals1.setSize(Vector2f(150, 80));
	freeMeals1.setPosition(5, 335);
	freeMeals1.setFillColor(Color::White);
	freeMealspic1.loadFromFile("freemealsoff.png");
	freeMeals1.setTexture(&freeMealspic1);


	freeMeals2.setSize(Vector2f(150, 80));
	freeMeals2.setPosition(5, 335);
	freeMeals2.setFillColor(Color::White);
	freeMealspic2.loadFromFile("freemealsON.png");
	freeMeals2.setTexture(&freeMealspic2);

	////////////////////////////////////////////////

	

	stars1.setSize(Vector2f(450, 80));
	stars1.setPosition(5, 415);
	stars1.setFillColor(Color::White);
	starspic1.loadFromFile("1.png");
	stars1.setTexture(&starspic1);

	stars2.setSize(Vector2f(450, 80));
	stars2.setPosition(5, 415);
	stars2.setFillColor(Color::White);
	starspic2.loadFromFile("2.png");
	stars2.setTexture(&starspic2);

	stars3.setSize(Vector2f(450, 80));
	stars3.setPosition(5, 415);
	stars3.setFillColor(Color::White);
	starspic3.loadFromFile("3.png");
	stars3.setTexture(&starspic3);

	stars4.setSize(Vector2f(450, 80));
	stars4.setPosition(5, 415);
	stars4.setFillColor(Color::White);
	starspic4.loadFromFile("4.png");
	stars4.setTexture(&starspic4);

	stars5.setSize(Vector2f(450, 80));
	stars5.setPosition(5, 415);
	stars5.setFillColor(Color::White);
	starspic5.loadFromFile("5.png");
	stars5.setTexture(&starspic5);
	int x = 0;
	for (int i = 0; i < 2; i++)
	{
		box[i].setSize(Vector2f(300, 70));
		box[i].setPosition(180, 5+x);
		box[i].setFillColor(Color::White);
		x += 77;
	}
	int y = 0;
	unordered_map<string, string> ::iterator it;
	it=linked.nam[i].head->value.comment.begin();
	for (int j = 0; j < 2 && it!= linked.nam[i].head->value.comment.end(); j++)
	{
		string s=it->first + ": " + it->second;
		cout << it->first << ": " << it->second;
		boxtext[j].setCharacterSize(30);
		boxtext[j].setFillColor(sf::Color::Black);
		boxtext[j].setStyle(Text::Bold);
		boxtext[j].setFont(use_font);
		boxtext[j].setString(s);
		boxtext[j].setPosition(305, 5+y);
		y += 77;
		it++;
	}

	boxrate.setSize(Vector2f(100, 100));
	boxrate.setPosition(290, 260);
	boxrate.setFillColor(Color::White);


	string str= to_string(linked.nam[i].head->value.rate) ;
	cout << str;
	boxrate1.setCharacterSize(30);
	boxrate1.setFillColor(sf::Color::Black);
	boxrate1.setStyle(Text::Bold);
	boxrate1.setFont(use_font);
	boxrate1.setPosition(270, 270);
	boxrate1.setString(str);

	//////////////////////////////////////////////////
	sf::RenderWindow hotelinformation(sf::VideoMode(500, 1000), "Hotelinformation");
	while (hotelinformation.isOpen())
	{
		mouse_position.x = sf::Mouse::getPosition(hotelinformation).x;
		mouse_position.y = sf::Mouse::getPosition(hotelinformation).y;
		Event event;

		while (hotelinformation.pollEvent(event))
		{











			


			if (event.type == sf::Event::Closed)
				hotelinformation.close();
		}


		hotelinformation.clear();
		hotelinformation.draw(wallpaper);
		hotelinformation.draw(wallpaper2);
		hotelinformation.draw(nametext);

		for (int i = 0; i < 2; i++)
		{
			hotelinformation.draw(boxtext[i]);
			
			
			
		}
		
		hotelinformation.draw(boxrate1);

		hotelinformation.draw(boxrate);
		hotelinformation.draw(countrytext);
		if (linked.nam[i].head->value.pool== false)
		{
			hotelinformation.draw(pool1);
		}
		else if (linked.nam[i].head->value.pool == true)
		{
			hotelinformation.draw(pool2);
		}
		


		if (linked.nam[i].head->value.gym == false)
		{
			hotelinformation.draw(gym1);
		}
		else if (linked.nam[i].head->value.gym == true)
		{
			hotelinformation.draw(gym2);
		}


		if (linked.nam[i].head->value.free_meals == false)
		{
			hotelinformation.draw(freeMeals1);
		}
		else if (linked.nam[i].head->value.free_meals == true)
		{
			hotelinformation.draw(freeMeals2);
		}


		if (linked.nam[i].head->value.num_stars == 1)
		{
			hotelinformation.draw(stars1);
		}
		else if (linked.nam[i].head->value.num_stars == 2)
		{
			hotelinformation.draw(stars2);
		}
		else if (linked.nam[i].head->value.num_stars == 3)
		{
			hotelinformation.draw(stars3);
		}
		else if (linked.nam[i].head->value.num_stars == 4)
		{
			hotelinformation.draw(stars4);
		}
		else if (linked.nam[i].head->value.num_stars == 5)
		{
			hotelinformation.draw(stars5);
		}
	
		hotelinformation.display();


		
	}



}

void guestrc()
{
	bool commentshape = false;
	bool rateshape = false;
	sf::RenderWindow guestrc(sf::VideoMode(500, 700), "guestInfromation");
	RectangleShape wallpaper,HotelName,comment,rate,guestname,guestrate,guestcomment;
	Texture HotelNameTexture,guestnamepic,guestratepic,commentpic,rateoic,guestcommentpic , guestnamepicpicpic;
	Text namehotel, nameguest, rateguest ,commentguest;

	Font use_font;
	use_font.loadFromFile("ArialCE.ttf");



	wallpaper.setSize(Vector2f(500, 700));
	wallpaper.setFillColor(Color::White);
	HotelNameTexture.loadFromFile("hotelname.png");
	HotelName.setSize(Vector2f(400, 100));
	HotelName.setPosition(5, 5);
	HotelName.setTexture(&HotelNameTexture);

	commentpic.loadFromFile("comment.png");
	comment.setSize(Vector2f(300, 80));
	comment.setPosition(5, 130);
	comment.setTexture(&commentpic);
	

	rateoic.loadFromFile("rate.png");
	rate.setSize(Vector2f(300, 80));
	rate.setPosition(5, 230);
	rate.setTexture(&rateoic);



	namehotel.setCharacterSize(50);
	namehotel.setFillColor(sf::Color::Black);
	namehotel.setStyle(Text::Bold);
	namehotel.setFont(use_font);
	namehotel.setPosition(10, 30);



	nameguest.setCharacterSize(30);
	nameguest.setFillColor(sf::Color::Black);
	nameguest.setStyle(Text::Bold);
	nameguest.setFont(use_font);
	nameguest.setPosition(10, 420);




	rateguest.setCharacterSize(30);
	rateguest.setFillColor(sf::Color::Black);
	rateguest.setStyle(Text::Bold);
	rateguest.setFont(use_font);
	rateguest.setPosition(10, 320);





	commentguest.setCharacterSize(30);
	commentguest.setFillColor(sf::Color::Black);
	commentguest.setStyle(Text::Bold);
	commentguest.setFont(use_font);
	commentguest.setPosition(10, 570);
	



	guestnamepicpicpic.loadFromFile("gusetname.png");
	guestname.setSize(Vector2f(400, 100));
	guestname.setPosition(5, 400);
	guestname.setTexture(&guestnamepicpicpic);

	guestcommentpic.loadFromFile("commentcomment.png");
	guestcomment.setSize(Vector2f(400, 100));
	guestcomment.setPosition(5, 550);
	guestcomment.setTexture(&guestcommentpic);



	guestrate.setSize(Vector2f(400, 100));
	guestrate.setPosition(5, 280);
	guestratepic.loadFromFile("ratefrom1to5.png");
	guestrate.setTexture(&guestratepic);






	while (guestrc.isOpen())
	{
		Event event;
		mouse_position.x = sf::Mouse::getPosition(guestrc).x;
		mouse_position.y = sf::Mouse::getPosition(guestrc).y;
		while (guestrc.pollEvent(event))
		{

			if (focus(HotelName.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						hotelnameC += event.text.unicode;
						namehotel.setString(hotelnameC);

					}
					if (event.text.unicode == 8 && hotelnameC.size() > 0)
					{
						hotelnameC.erase(hotelnameC.begin() + hotelnameC.size() - 1);
						namehotel.setString(hotelnameC);
						cout << hotelnameC;





					}
				}

			}
			



			if (focus(guestname.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						hotelguestname += event.text.unicode;
						nameguest.setString(hotelguestname);

					}
					if (event.text.unicode == 8 && hotelguestname.size() > 0)
					{
						hotelguestname.erase(hotelguestname.begin() + hotelguestname.size() - 1);
						nameguest.setString(hotelguestname);
						cout << hotelguestname;





					}
				}

			}
			

			if (focus(guestcomment.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						hotelguestcomment += event.text.unicode;
						commentguest.setString(hotelguestcomment);

					}
					if (event.text.unicode == 8 && hotelguestcomment.size() > 0)
					{
						hotelguestcomment.erase(hotelguestcomment.begin() + hotelguestcomment.size() - 1);
						commentguest.setString(hotelguestcomment);
						cout << hotelguestcomment;





					}
				}

			}





			if (focus(guestrate.getGlobalBounds(), mouse_position))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && event.text.unicode != 8)
					{
						hotelguestrate += event.text.unicode;
						rateguest.setString(hotelguestrate);

					}
					if (event.text.unicode == 8 && hotelguestrate.size() > 0)
					{
						hotelguestrate.erase(hotelguestrate.begin() + hotelguestrate.size() - 1);
						rateguest.setString(hotelguestrate);
						cout << hotelguestrate;





					}
				}

			}













			if (focus(comment.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					commentshape = true;
					
				}

			if (focus(rate.getGlobalBounds(), mouse_position))
				if (event.type == sf::Event::MouseButtonPressed  && event.mouseButton.button == sf::Mouse::Left)
				{
					rateshape = true;

					
				}


			if (event.type == sf::Event::Closed)
			{
				

				if (hotelguestrate != "")
				{
					int number = hotelguestrate[0] - 48;
					cout << number;
					linked.append_rate(hotelnameC,number);
				}
				if (hotelguestname != "")
				{
					linked.append_comments(hotelnameC, hotelguestname, hotelguestcomment);
				}



				hotelnameC = "";
				hotelguestname = "";
				hotelguestcomment = "";
				hotelguestrate = "";



				guestrc.close();




			}

		}




		
		guestrc.clear();
		guestrc.draw(wallpaper);
		guestrc.draw(HotelName);
		guestrc.draw(namehotel);

		if (commentshape == false)
		{
			guestrc.draw(comment);


		}
		if (commentshape == true)

		{
			guestrc.draw(guestname);
			guestrc.draw(nameguest);
			
			
			guestrc.draw(guestcomment);
			guestrc.draw(commentguest);


		}
		if (rateshape == false)
		{
			guestrc.draw(rate);
		}
		if (rateshape == true)
		{
			
			guestrc.draw(guestrate);
			guestrc.draw(rateguest);
			
		}


		guestrc.display();
	}





}