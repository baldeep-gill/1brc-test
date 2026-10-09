#include <array>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <map>

static constexpr std::array<std::string_view, 100> stations = {
    "London","Birmingham","Manchester","Liverpool","Leeds","Sheffield","Bristol","Newcastle upon Tyne","Nottingham","Leicester","Coventry","Southampton","Portsmouth","Oxford","Cambridge","Norwich","York","Hull","Stoke-on-Trent","Derby","Wolverhampton","Reading","Milton Keynes","Luton","Swindon","Gloucester","Cheltenham","Worcester","Hereford","Bath","Exeter","Plymouth","Truro","Taunton","Bournemouth","Poole","Salisbury","Winchester","Brighton","Hastings","Chichester","Canterbury","Dover","Maidstone","Guildford","Woking","Ipswich","Colchester","Peterborough","Northampton","Lincoln","Grimsby","Scarborough","Harrogate","Skipton","Blackpool","Preston","Lancaster","Carlisle","Kendal","Barrow-in-Furness","Chester","Crewe","Shrewsbury","Telford","Oswestry","Durham","Sunderland","Middlesbrough","Darlington","Alnwick","Berwick-upon-Tweed","Edinburgh","Glasgow","Aberdeen","Dundee","Inverness","Perth","Stirling","Falkirk","Ayr","Dumfries","Oban","Fort William","St Andrews","Cardiff","Swansea","Newport","Wrexham","Bangor","Aberystwyth","Carmarthen","Llandudno","Holyhead","Belfast","Londonderry","Lisburn","Newry","Coleraine","Enniskillen"
};

std::map<std::string_view, double> station_centres{};

int main(int argc, char* argv[]) {
    long long num_entries = 100000;

    if (argc > 1) {
        num_entries = std::stoll(argv[1]);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, stations.size() - 1);
    std::uniform_int_distribution<> station_dis(-99, 399);

    for (const auto& station: stations) {
        station_centres[station] = static_cast<double>(station_dis(gen) / 10.0);
    }

    for (long long i = 0; i < num_entries; ++i) {
        std::string_view name = stations[dis(gen)];
        
        std::normal_distribution<double> temp_dis(station_centres[name], 1.5);

        double temp = static_cast<double>(temp_dis(gen));
        
        std::cout << name << ";" << std::fixed << std::setprecision(1) << temp << "\n";
    }

    return 0;
}