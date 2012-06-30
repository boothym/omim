#include "platform.hpp"

#include "../coding/sha2.hpp"
#include "../coding/base64.hpp"

#include "../base/logging.hpp"


string Platform::ReadPathForFile(string const & file) const
{
  string fullPath = m_writableDir + file;
  if (!IsFileExistsByFullPath(fullPath))
  {
    fullPath = m_resourcesDir + file;
    if (!IsFileExistsByFullPath(fullPath))
      MYTHROW(FileAbsentException, ("File doesn't exist", fullPath));
  }
  return fullPath;
}

string Platform::HashUniqueID(string const & s)
{
  // generate sha2 hash for UUID
  string const hash = sha2::digest256(s, false);
  // xor it
  size_t const offset = hash.size() / 4;
  string xoredHash;
  for (size_t i = 0; i < offset; ++i)
    xoredHash.push_back(hash[i] ^ hash[i + offset] ^ hash[i + offset * 2] ^ hash[i + offset * 3]);
  // and use base64 encoding
  return base64::encode(xoredHash);
}

string Platform::MetaServerUrl() const
{
  return "http://active.servers.url";
}

string Platform::DefaultUrlsJSON() const
{
  return "[\"http://1st.default.server/\",\"http://2nd.default.server/\",\"http://3rd.default.server/\"]";
}

void Platform::GetFontNames(FilesList & res) const
{
  string arr[] = { WritableDir(), ResourcesDir() };

  for (size_t i = 0; i < ARRAY_SIZE(arr); ++i)
  {
    LOG(LDEBUG, ("Searching for fonts in", arr[i]));
    GetFilesInDir(arr[i], "*.ttf", res);
  }

  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());

  LOG(LDEBUG, ("Font files:", (res)));
}
