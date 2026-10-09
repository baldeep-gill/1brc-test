#include <array>
#include <iostream>
#include <random>
#include <string>

struct WeatherStation {
    std::string name;
    float temp;
};

    static constexpr std::array<std::string_view, 100> stations = {
        "London","Birmingham","Manchester","Liverpool","Leeds","Sheffield","Bristol","Newcastle upon Tyne","Nottingham","Leicester","Coventry","Southampton","Portsmouth","Oxford","Cambridge","Norwich","York","Hull","Stoke-on-Trent","Derby","Wolverhampton","Reading","Milton Keynes","Luton","Swindon","Gloucester","Cheltenham","Worcester","Hereford","Bath","Exeter","Plymouth","Truro","Taunton","Bournemouth","Poole","Salisbury","Winchester","Brighton","Hastings","Chichester","Canterbury","Dover","Maidstone","Guildford","Woking","Ipswich","Colchester","Peterborough","Northampton","Lincoln","Grimsby","Scarborough","Harrogate","Skipton","Blackpool","Preston","Lancaster","Carlisle","Kendal","Barrow-in-Furness","Chester","Crewe","Shrewsbury","Telford","Oswestry","Durham","Sunderland","Middlesbrough","Darlington","Alnwick","Berwick-upon-Tweed","Edinburgh","Glasgow","Aberdeen","Dundee","Inverness","Perth","Stirling","Falkirk","Ayr","Dumfries","Oban","Fort William","St Andrews","Cardiff","Swansea","Newport","Wrexham","Bangor","Aberystwyth","Carmarthen","Llandudno","Holyhead","Belfast","Londonderry","Lisburn","Newry","Coleraine","Enniskillen"
    };

int main(int argc, char* argv[]) {
    long long num_stations = 100000;

    if (argc > 1) {
        num_stations = std::stoll(argv[1]);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, stations.size() - 1);
    std::uniform_int_distribution<> temp_dis(-99, 999);

    for (long long i = 0; i < num_stations; ++i) {
        std::string_view name = stations[dis(gen)];
        float temp = static_cast<float>(temp_dis(gen) / 10.0f);
        
        std::cout << name << ";" << temp << "\n";
    }

    return 1;
}