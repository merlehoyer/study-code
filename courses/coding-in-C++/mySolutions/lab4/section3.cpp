#include <iostream>
#include <string>

class AudioFile
{
public:
    virtual void play() const
    {
        std::cout << "Playing generic audio file\n";
    }

    virtual void print_info() const
    {
        std::cout << "Generic audio file\n";
    }

    virtual ~AudioFile()
    {
        std::cout << "AudioFile destroyed\n";
    }
};

class MP3File : public AudioFile
{
private:
    std::string artist;

public:
    MP3File(const std::string& artist_name)
        : artist(artist_name)
    {
    }

    void play() const override
    {
        std::cout << "Playing MP3 by " << artist << "\n";
    }

    void print_info() const override
    {
        std::cout << "MP3 file by " << artist << "\n";
    }

    ~MP3File() override
    {
        std::cout << "MP3File destroyed\n";
    }
};

class WAVFile : public AudioFile
{
public:
    void play() const override
    {
        std::cout << "Playing WAV file\n";
    }

    void print_info() const override
    {
        std::cout << "Uncompressed WAV file\n";
    }

    ~WAVFile() override
    {
        std::cout << "WAVFile destroyed\n";
    }
};

int main()
{
    AudioFile* playlist[2];

    playlist[0] = new MP3File("Daft Punk");
    playlist[1] = new WAVFile();

    for (int index = 0; index < 2; index++)
    {
        playlist[index]->print_info();
        playlist[index]->play();
    }

    for (int index = 0; index < 2; index++)
    {
        delete playlist[index];
    }

    return 0;
}

//Error complier does not know which function is meant ->needs const function so that it is an exact replica -> check with override
// does function from basisclass
// to be overriden functions have to be declared virtual