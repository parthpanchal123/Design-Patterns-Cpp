#include <iostream>

using namespace std;

enum Theme
{
    THEME_DARK,
    THEME_LIGHT
};

class ThemeController
{
    static ThemeController *_themeContollerInstance;
    int _themeType;

public:
    ThemeController() : _themeType(Theme::THEME_LIGHT)
    {
    }

    static ThemeController *getThemeContollerInstance()
    {
        if (_themeContollerInstance == NULL)
        {
            _themeContollerInstance = new ThemeController();
        }

        return _themeContollerInstance;
    }
    // setter
    void setTheme(int _themeType)
    {
        this->_themeType = _themeType;
    }

    // getter more
    int getTheme()
    {
        return _themeType;
    }
};

ThemeController *ThemeController ::_themeContollerInstance = NULL;

int main(int argc, char const *argv[])
{
    ThemeController *tc = ThemeController::getThemeContollerInstance();

    tc->getTheme() == 0 ? cout << "Dark Theme\n" : cout << "Light Theme\n";

    tc->setTheme(Theme::THEME_DARK);

    tc->getTheme() == 0 ? cout << "Dark Theme\n" : cout << "Light Theme\n";

    delete tc;

    return 0;
}
