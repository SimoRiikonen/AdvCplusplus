// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#include <fstream>
struct FileNotFoundException : public std::exception{};

class FileController
{
public:
	static void LoadInfo(Player & p)
	{
		try 
		{
			ifstream f("playerdata.txt");
			if (!f.is_open())
			{
				throw FileNotFoundException();
			}
			else 
			{ 
				while (!f.eof())
				{
					string line;
					f >> line;
					if ( line == "#player")
					{
					  int iTmp;
					  unsigned int uiTmp;
					  string strTmp;
					  char g;
					  f >> strTmp; p.SetName(strTmp); 
					  f >> iTmp; p.SetClass((Class)iTmp);
					  f >> iTmp; p.SetAge(iTmp);
					  f >> g; p.SetGender( (g == 'm' ? Male : Female) );
					  f >> iTmp; p.SetExperience(iTmp); 
					  f >> iTmp; p.SetGoldAmount(iTmp);
					}
				}
			}
		}
		catch (FileNotFoundException & e)
		{
			std::cout << "\nCould not load data from a file. Create a new character. \n";
			p.SetName("ERROR");
		}
	}
	static void SaveInfo(Player & p)
	{
		ofstream f("playerdata.txt");
		string saveFile = "#player";
		f << saveFile<< endl; 
		f << p.GetName() << endl; 
		f << p.GetClass()<< endl;
		f << p.GetAge()<< endl;
		f << p.GetGender()<< endl;
		f << p.GetExperience()<< endl;
		f << p.GetPurse().GetGoldAmount()<< endl;
		f.close();
	}
};