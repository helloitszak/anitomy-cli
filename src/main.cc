#include <iostream>
#include <anitomy/anitomy.h>
#include <json.hpp>
#include <codecvt>

using json = nlohmann::json;

std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
std::string ws2s(const std::wstring& wstr)
{
  return converter.to_bytes(wstr);
}

std::wstring s2ws(const std::string& str)
{
  return converter.from_bytes(str);
}

std::string get_str_element(anitomy::Elements eles, anitomy::ElementCategory cat)
{
  return ws2s(eles.get(cat));
}

int main() {
  anitomy::Anitomy anitomy;

  std::string line;
  std::getline(std::cin, line);
  
  anitomy.Parse(s2ws(line));
  
  auto& elements = anitomy.elements();
  json output = {
    { "season", get_str_element(elements, anitomy::kElementAnimeSeason) },
    { "seasonPrefix", get_str_element(elements, anitomy::kElementAnimeSeasonPrefix) },
    { "animeTitle", get_str_element(elements, anitomy::kElementAnimeTitle)},
    { "animeType", get_str_element(elements, anitomy::kElementAnimeType)},
    { "animeYear", get_str_element(elements, anitomy::kElementAnimeYear)},
    { "autoTerm", get_str_element(elements, anitomy::kElementAudioTerm)},
    { "deviceCompatibility", get_str_element(elements, anitomy::kElementDeviceCompatibility)},
    { "episodeNumber", get_str_element(elements, anitomy::kElementEpisodeNumber)},
    { "episodePrefix", get_str_element(elements, anitomy::kElementEpisodePrefix)},
    { "episodeTitle", get_str_element(elements, anitomy::kElementEpisodeTitle)},
    { "fileChecksum", get_str_element(elements, anitomy::kElementFileChecksum)},
    { "fileExtension", get_str_element(elements, anitomy::kElementFileExtension)},
    { "fileName", get_str_element(elements, anitomy::kElementFileName)},
    { "language", get_str_element(elements, anitomy::kElementLanguage)},
    { "other", get_str_element(elements, anitomy::kElementOther)},
    { "releaseGroup", get_str_element(elements, anitomy::kElementReleaseGroup)},
    { "releaseInformation", get_str_element(elements, anitomy::kElementReleaseInformation)},
    { "releaseVersion", get_str_element(elements, anitomy::kElementReleaseVersion)},
    { "source", get_str_element(elements, anitomy::kElementSource)},
    { "subtitles", get_str_element(elements, anitomy::kElementSubtitles)},
    { "videoResolution", get_str_element(elements, anitomy::kElementVideoResolution)},
    { "videoTerm", get_str_element(elements, anitomy::kElementVideoTerm)},
    { "volumeNumber", get_str_element(elements, anitomy::kElementVolumeNumber)},
    { "volumePrefix", get_str_element(elements, anitomy::kElementVolumePrefix)}
  };

  std::cout << output << std::endl;
  
  return 0;
}