//
// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "zetasql/parser/keywords.h"

#include <cctype>
#include <cstdint>
#include <limits>
#include <memory>
#include <unordered_map>
#include <utility>

#include "zetasql/base/logging.h"
#include <cstdint>
#include "absl/base/macros.h"
#include "absl/memory/memory.h"
#include "absl/strings/ascii.h"
#include "zetasql/base/map_util.h"

enum BisonKeywordTokenCode {
// This is a generated file that contains just the lines of the form KW_... =
// in the bison parser. We don't want to take a full compilation dependency on
// the parser because that would create cyclic dependencies.
#include "zetasql/parser/bison_keyword_token_codes.inc"
};

namespace zetasql {
namespace parser {

namespace {

struct KeywordInfoPOD {
  absl::string_view keyword;
  int bison_token;
  KeywordInfo::KeywordClass keyword_class = KeywordInfo::kNotReserved;
};

constexpr KeywordInfoPOD kAllKeywords[] = {
    {"abort", KW_ABORT},
    {"access", KW_ACCESS},
    {"action", KW_ACTION},
    {"add", KW_ADD},
    {"aggregate", KW_AGGREGATE},
    {"all", KW_ALL, KeywordInfo::kReserved},
    {"alter", KW_ALTER},
    {"analyze", KW_ANALYZE},
    {"and", KW_AND, KeywordInfo::kReserved},
    {"anonymization", KW_ANONYMIZATION},
    {"any", KW_ANY, KeywordInfo::kReserved},
    {"array", KW_ARRAY, KeywordInfo::kReserved},
    {"as", KW_AS, KeywordInfo::kReserved},
    {"asc", KW_ASC, KeywordInfo::kReserved},
    {"assert", KW_ASSERT},
    {"assert_rows_modified", KW_ASSERT_ROWS_MODIFIED, KeywordInfo::kReserved},
    {"at", KW_AT, KeywordInfo::kReserved},
    {"batch", KW_BATCH},
    {"begin", KW_BEGIN},
    {"between", KW_BETWEEN, KeywordInfo::kReserved},
    {"bigdecimal", KW_BIGDECIMAL},
    {"bignumeric", KW_BIGNUMERIC},
    {"break", KW_BREAK},
    {"by", KW_BY, KeywordInfo::kReserved},
    {"call", KW_CALL},
    {"cascade", KW_CASCADE},
    {"case", KW_CASE, KeywordInfo::kReserved},
    {"cast", KW_CAST, KeywordInfo::kReserved},
    {"check", KW_CHECK},
    {"clamped", KW_CLAMPED},
    {"cluster", KW_CLUSTER},
    {"collate", KW_COLLATE, KeywordInfo::kReserved},
    {"column", KW_COLUMN},
    {"columns", KW_COLUMNS},
    {"commit", KW_COMMIT},
    {"config", KW_CONFIG, KeywordInfo::kReserved},
    {"connection", KW_CONNECTION},
    {"const", KW_CONST},
    {"constant", KW_CONSTANT},
    {"constraint", KW_CONSTRAINT},
    {"contains", KW_CONTAINS, KeywordInfo::kReserved},
    {"continue", KW_CONTINUE},
    {"clone", KW_CLONE},
    {"create", KW_CREATE, KeywordInfo::kReserved},
    {"cross", KW_CROSS, KeywordInfo::kReserved},
    {"cube", KW_CUBE, KeywordInfo::kReserved},
    {"current", KW_CURRENT, KeywordInfo::kReserved},
    {"current_time", KW_CURRENT_TIME},
    {"current_row", KW_CURRENT_ROW},
    {"data", KW_DATA},
    {"database", KW_DATABASE},
    {"date", KW_DATE},
    {"datetime", KW_DATETIME},
    {"decimal", KW_DECIMAL},
    {"declare", KW_DECLARE},
    {"default", KW_DEFAULT, KeywordInfo::kReserved},
    {"define", KW_DEFINE, KeywordInfo::kReserved},
    {"definer", KW_DEFINER},
    {"delete", KW_DELETE},
    {"deploy", KW_DEPLOY},
    {"deployment", KW_DEPLOYMENT},
    {"desc", KW_DESC, KeywordInfo::kReserved},
    {"describe", KW_DESCRIBE},
    {"descriptor", KW_DESCRIPTOR},
    {"deterministic", KW_DETERMINISTIC},
    {"distinct", KW_DISTINCT, KeywordInfo::kReserved},
    {"div", KW_IDIVIDE, KeywordInfo::kReserved},
    {"do", KW_DO},
    {"drop", KW_DROP},
    {"else", KW_ELSE, KeywordInfo::kReserved},
    {"elseif", KW_ELSEIF},
    {"end", KW_END, KeywordInfo::kReserved},
    {"enforced", KW_ENFORCED},
    {"enum", KW_ENUM, KeywordInfo::kReserved},
    {"error", KW_ERROR},
    {"escape", KW_ESCAPE, KeywordInfo::kReserved},
    {"except", KW_EXCEPT, KeywordInfo::kReserved},
    {"exception", KW_EXCEPTION},
    {"exclude", KW_EXCLUDE, KeywordInfo::kReserved},
    {"execute", KW_EXECUTE},
    {"exists", KW_EXISTS, KeywordInfo::kReserved},
    {"explain", KW_EXPLAIN},
    {"export", KW_EXPORT},
    {"external", KW_EXTERNAL},
    {"extract", KW_EXTRACT, KeywordInfo::kReserved},
    {"false", KW_FALSE, KeywordInfo::kReserved},
    {"fetch", KW_FETCH, KeywordInfo::kReserved},
    {"filter", KW_FILTER},
    {"filter_fields", KW_FILTER_FIELDS},
    {"fill", KW_FILL},
    {"first", KW_FIRST},
    {"following", KW_FOLLOWING, KeywordInfo::kReserved},
    {"for", KW_FOR, KeywordInfo::kReserved},
    {"foreign", KW_FOREIGN},
    {"format", KW_FORMAT},
    {"from", KW_FROM, KeywordInfo::kReserved},
    {"full", KW_FULL, KeywordInfo::kReserved},
    {"function", KW_FUNCTION},
    {"generated", KW_GENERATED},
    {"global", KW_GLOBAL},
    {"grant", KW_GRANT},
    {"group", KW_GROUP, KeywordInfo::kReserved},
    {"group_rows", KW_GROUP_ROWS},
    {"grouping", KW_GROUPING, KeywordInfo::kReserved},
    {"groups", KW_GROUPS, KeywordInfo::kReserved},
    {"hash", KW_HASH, KeywordInfo::kReserved},
    {"having", KW_HAVING, KeywordInfo::kReserved},
    {"hidden", KW_HIDDEN},
    {"if", KW_IF, KeywordInfo::kReserved},
    {"ignore", KW_IGNORE, KeywordInfo::kReserved},
    {"immediate", KW_IMMEDIATE},
    {"immutable", KW_IMMUTABLE},
    {"import", KW_IMPORT},
    {"in", KW_IN, KeywordInfo::kReserved},
    {"include", KW_INCLUDE},
    {"inout", KW_INOUT},
    {"index", KW_INDEX, KeywordInfo::kReserved},
    {"infile", KW_INFILE},
    {"inner", KW_INNER, KeywordInfo::kReserved},
    {"insert", KW_INSERT},
    {"instance_not_in_window", KW_INSTANCE_NOT_IN_WINDOW, KeywordInfo::kReserved},
    {"intersect", KW_INTERSECT, KeywordInfo::kReserved},
    {"interval", KW_INTERVAL, KeywordInfo::kReserved},
    {"iterate", KW_ITERATE},
    {"into", KW_INTO, KeywordInfo::kReserved},
    {"invoker", KW_INVOKER},
    {"is", KW_IS, KeywordInfo::kReserved},
    {"isolation", KW_ISOLATION},
    {"job", KW_JOB},
    {"join", KW_JOIN, KeywordInfo::kReserved},
    {"json", KW_JSON},
    {"key", KW_KEY},
    {"language", KW_LANGUAGE},
    {"last", KW_LAST, KeywordInfo::kReserved},
    {"lateral", KW_LATERAL, KeywordInfo::kReserved},
    {"leave", KW_LEAVE},
    {"left", KW_LEFT, KeywordInfo::kReserved},
    {"level", KW_LEVEL},
    {"like", KW_LIKE, KeywordInfo::kReserved},
    {"ilike", KW_ILIKE, KeywordInfo::kReserved},
    {"limit", KW_LIMIT, KeywordInfo::kReserved},
    {"load", KW_LOAD},
    {"lookup", KW_LOOKUP, KeywordInfo::kReserved},
    {"loop", KW_LOOP},
    {"match", KW_MATCH},
    {"matched", KW_MATCHED},
    {"materialized", KW_MATERIALIZED},
    {"max", KW_MAX},
    {"maxsize", KW_MAXSIZE},
    {"message", KW_MESSAGE},
    {"min", KW_MIN},
    {"mod", KW_MOD, KeywordInfo::kReserved},
    {"model", KW_MODEL},
    {"module", KW_MODULE},
    {"merge", KW_MERGE, KeywordInfo::kReserved},
    {"natural", KW_NATURAL, KeywordInfo::kReserved},
    {"new", KW_NEW, KeywordInfo::kReserved},
    {"no", KW_NO, KeywordInfo::kReserved},
    {"not", KW_NOT, KeywordInfo::kReserved},
    {"null", KW_NULL, KeywordInfo::kReserved},
    {"nulls", KW_NULLS, KeywordInfo::kReserved},
    {"numeric", KW_NUMERIC},
    {"of", KW_OF, KeywordInfo::kReserved},
    {"offset", KW_OFFSET},
    {"on", KW_ON, KeywordInfo::kReserved},
    {"only", KW_ONLY},
    {"open", KW_OPEN, KeywordInfo::kReserved},
    {"options", KW_OPTIONS},
    {"or", KW_OR, KeywordInfo::kReserved},
    {"order", KW_ORDER, KeywordInfo::kReserved},
    {"out", KW_OUT},
    {"outfile", KW_OUTFILE},
    {"outer", KW_OUTER, KeywordInfo::kReserved},
    {"over", KW_OVER, KeywordInfo::kReserved},
    {"partition", KW_PARTITION, KeywordInfo::kReserved},
    {"percent", KW_PERCENT},
    {"pivot", KW_PIVOT},
    {"unpivot", KW_UNPIVOT},
    {"policies", KW_POLICIES},
    {"policy", KW_POLICY},
    {"primary", KW_PRIMARY},
    {"preceding", KW_PRECEDING, KeywordInfo::kReserved},
    {"procedure", KW_PROCEDURE},
    {"private", KW_PRIVATE},
    {"privileges", KW_PRIVILEGES},
    {"proto", KW_PROTO, KeywordInfo::kReserved},
    {"public", KW_PUBLIC},
    {"qualify", KW_QUALIFY},
    {"raise", KW_RAISE},
    {"range", KW_RANGE, KeywordInfo::kReserved},
    {"read", KW_READ},
    {"recursive", KW_RECURSIVE, KeywordInfo::kReserved},
    {"references", KW_REFERENCES},
    {"rename", KW_RENAME},
    {"repeat", KW_REPEAT},
    {"repeatable", KW_REPEATABLE},
    {"replace", KW_REPLACE},
    {"replace_fields", KW_REPLACE_FIELDS},
    {"respect", KW_RESPECT, KeywordInfo::kReserved},
    {"restrict", KW_RESTRICT},
    {"return", KW_RETURN},
    {"returns", KW_RETURNS},
    {"revoke", KW_REVOKE},
    {"right", KW_RIGHT, KeywordInfo::kReserved},
    {"rollback", KW_ROLLBACK},
    {"rollup", KW_ROLLUP, KeywordInfo::kReserved},
    {"row", KW_ROW},
    {"rows", KW_ROWS, KeywordInfo::kReserved},
    {"rows_range", KW_ROWS_RANGE, KeywordInfo::kReserved},
    {"run", KW_RUN},
    {"safe_cast", KW_SAFE_CAST},
    {"schema", KW_SCHEMA},
    {"search", KW_SEARCH},
    {"security", KW_SECURITY},
    {"select", KW_SELECT, KeywordInfo::kReserved},
    {"session", KW_SESSION},
    {"set", KW_SET, KeywordInfo::kReserved},
    {"show", KW_SHOW},
    {"simple", KW_SIMPLE},
    {"some", KW_SOME, KeywordInfo::kReserved},
    {"source", KW_SOURCE},
    {"storing", KW_STORING},
    {"stop", KW_STOP},
    {"sql", KW_SQL},
    {"stable", KW_STABLE},
    {"start", KW_START},
    {"status", KW_STATUS},
    {"stored", KW_STORED},
    {"struct", KW_STRUCT, KeywordInfo::kReserved},
    {"system", KW_SYSTEM},
    {"system_time", KW_SYSTEM_TIME},
    {"table", KW_TABLE},
    {"tablesample", KW_TABLESAMPLE, KeywordInfo::kReserved},
    {"target", KW_TARGET},
    {"temp", KW_TEMP},
    {"temporary", KW_TEMPORARY},
    {"then", KW_THEN, KeywordInfo::kReserved},
    {"time", KW_TIME},
    {"timestamp", KW_TIMESTAMP},
    {"to", KW_TO, KeywordInfo::kReserved},
    {"transaction", KW_TRANSACTION},
    {"transform", KW_TRANSFORM},
    {"treat", KW_TREAT, KeywordInfo::kReserved},
    {"true", KW_TRUE, KeywordInfo::kReserved},
    {"truncate", KW_TRUNCATE},
    {"type", KW_TYPE},
    {"unbounded", KW_UNBOUNDED, KeywordInfo::kReserved},
    {"union", KW_UNION, KeywordInfo::kReserved},
    {"unnest", KW_UNNEST, KeywordInfo::kReserved},
    {"unique", KW_UNIQUE},
    {"until", KW_UNTIL},
    {"update", KW_UPDATE},
    {"use", KW_USE},
    {"using", KW_USING, KeywordInfo::kReserved},
    {"value", KW_VALUE},
    {"values", KW_VALUES},
    {"variables", KW_VARIABLES},
    {"volatile", KW_VOLATILE},
    {"view", KW_VIEW},
    {"views", KW_VIEWS},
    {"weight", KW_WEIGHT},
    {"when", KW_WHEN, KeywordInfo::kReserved},
    {"where", KW_WHERE, KeywordInfo::kReserved},
    {"while", KW_WHILE},
    {"window", KW_WINDOW, KeywordInfo::kReserved},
    {"with", KW_WITH, KeywordInfo::kReserved},
    {"within", KW_WITHIN, KeywordInfo::kReserved},
    {"write", KW_WRITE},
    {"xor", KW_XOR, KeywordInfo::kReserved},
    {"zone", KW_ZONE},
};

// A case insensitive trie implementation. The ValueType is the type of value
// stored inside the trie. The stored values are non-owned pointers to
// ValueType. The case insensitivity is ASCII only. The maximum number of
// prefixes that this can store is 64K.
//
// Benchmark results showed that the functions below are several times faster on
// a hit than using dense_hash_map with a case insensitive hash function and
// equality (140-180 ns versus 14 ns). The performance for a miss is about 7 ns
// in the benchmark.
template <typename ValueType>
class CaseInsensitiveAsciiAlphaTrie {
 public:
  CaseInsensitiveAsciiAlphaTrie() : nodes_(1, TrieNode()) {}

  // Inserts 'key' into the trie, with value 'value'. Crashes if a value for
  // 'key' is already present.
  void Insert(absl::string_view key, const ValueType* value) {
    int node_index = 0;
    for (int i = 0; i < key.size(); ++i) {
      ZETASQL_CHECK(isalpha(key[i]) || key[i] == '_') << key;
      unsigned char c = absl::ascii_toupper(key[i]) - '0';
      int next_node_index = nodes_[node_index].children[c];
      if (next_node_index == 0) {
        ZETASQL_CHECK_LT(nodes_.size(), std::numeric_limits<uint16_t>::max());
        next_node_index = nodes_.size();
        nodes_[node_index].children[c] = next_node_index;
        nodes_.emplace_back();
      }
      node_index = next_node_index;
    }
    ZETASQL_CHECK(nodes_[node_index].value == nullptr) << "Duplicate key " << key;
    nodes_[node_index].value = value;
  }

  // Looks up 'key' in the trie. Returns nullptr for a non-match, or otherwise
  // the matched key's value. 'key' must only contain alphanumeric ASCII
  // characters or '_'.
  const ValueType* Get(absl::string_view key) const {
    int node_index = 0;
    for (int i = 0; i < key.size(); ++i) {
      unsigned char c = absl::ascii_toupper(key[i]) - '0';
      if (c >= ABSL_ARRAYSIZE(nodes_[node_index].children)) return nullptr;
      int next_node_index = nodes_[node_index].children[c];
      if (next_node_index == 0) return nullptr;
      node_index = next_node_index;
    }
    return nodes_[node_index].value;
  }

 private:
  struct TrieNode {
    // Child nodes for each supported byte value. Each value is an index into
    // CaseInsensitiveAsciiAlphaTrie::nodes_. Value 0 means that the child
    // is not present. The number of entries is enough to store all characters
    // between '0' and '_' in ASCII. The entry at index i is for character
    // '0' + i.
    uint16_t children['_' - '0' + 1]{};

    // The stored value for this node, or NULL if this node is not in the trie.
    ValueType* value = nullptr;
  };

  // All the nodes in the trie. Node with index 0 is the root.
  std::vector<TrieNode> nodes_;
};
}  // namespace

static std::unique_ptr<const CaseInsensitiveAsciiAlphaTrie<const KeywordInfo>>
CreateReservedKeywordTrie() {
  const std::vector<KeywordInfo>& all_keywords = GetAllKeywords();
  auto trie =
      absl::make_unique<CaseInsensitiveAsciiAlphaTrie<const KeywordInfo>>();
  for (const KeywordInfo& keyword_info : all_keywords) {
    if (keyword_info.IsReserved()) {
      trie->Insert(keyword_info.keyword(), &keyword_info);
    }
  }
  return std::move(trie);
}

const KeywordInfo* GetReservedKeywordInfo(absl::string_view keyword) {
  static const auto& trie = *CreateReservedKeywordTrie().release();
  return trie.Get(keyword);
}

std::unique_ptr<const CaseInsensitiveAsciiAlphaTrie<const KeywordInfo>>
CreateKeywordTrie() {
  const auto& all_keywords = GetAllKeywords();
  auto trie =
      absl::make_unique<CaseInsensitiveAsciiAlphaTrie<const KeywordInfo>>();
  for (const auto& keyword_info : all_keywords) {
    trie->Insert(keyword_info.keyword(), &keyword_info);
  }
  return std::move(trie);
}

const KeywordInfo* GetKeywordInfo(absl::string_view keyword) {
  static const auto& trie = *CreateKeywordTrie().release();
  return trie.Get(keyword);
}

static std::unique_ptr<const std::unordered_map<int, const KeywordInfo*>>
CreateTokenToKeywordInfoMap() {
  const auto& all_keywords = GetAllKeywords();
  auto keyword_info_map =
      absl::make_unique<std::unordered_map<int, const KeywordInfo*>>();
  for (const KeywordInfo& keyword_info : all_keywords) {
    zetasql_base::InsertOrDie(keyword_info_map.get(), keyword_info.bison_token(),
                     &keyword_info);
  }
  return std::move(keyword_info_map);
}

const KeywordInfo* GetKeywordInfoForBisonToken(int bison_token) {
  static const auto& keyword_info_map =
      *CreateTokenToKeywordInfoMap().release();
  const KeywordInfo* const* info =
      zetasql_base::FindOrNull(keyword_info_map, bison_token);
  if (info == nullptr) {
    return nullptr;
  }
  return *info;
}

// TODO: Use a central map that is shared with the ZetaSQL JavaCC
// parser, and generate the tokenizer rules and bison token definitions from
// that. For now we have a test that validates that the reserved words are the
// same, but there are no tests that test how nonreserved words work. Also, the
// tokenizer rules are still hand maintained. We could add a test that verifies
// that the tokenizer recognizes each of the keywords, but that doesn't test if
// there are more keywords that it recognizes but that aren't in the list. :-/
const std::vector<KeywordInfo>& GetAllKeywords() {
  static const std::vector<KeywordInfo>* all_keywords = []() {
    std::vector<KeywordInfo>* keywords = new std::vector<KeywordInfo>();
    for (const KeywordInfoPOD& keyword : kAllKeywords) {
      keywords->push_back(
          {keyword.keyword, keyword.bison_token, keyword.keyword_class});
    }
    return keywords;
  }();
  return *all_keywords;
}

static std::unique_ptr<const CaseInsensitiveAsciiAlphaTrie<const KeywordInfo>>
CreateKeywordInTokenizerTrie() {
  auto trie =
      absl::make_unique<CaseInsensitiveAsciiAlphaTrie<const KeywordInfo>>();
  // These words are keywords in JavaCC, so we want to treat them as keywords in
  // the tokenizer API even though they are not always treated as keywords in
  // the Bison parser.
  for (const char* keyword : {
           "current_date",
           "current_time",
           "current_datetime",
           "current_timestamp",
           "current_timestamp_seconds",
           "current_timestamp_millis",
           "current_timestamp_micros",
       }) {
    // We don't care about the KeywordInfo, but we have to create one because
    // the trie needs a non-NULL value. We use an arbitrary bison token.
    KeywordInfo* keyword_info = new KeywordInfo(keyword, KW_SELECT);
    trie->Insert(keyword_info->keyword(), keyword_info);
  }
  return std::move(trie);
}

bool IsKeywordInTokenizer(absl::string_view identifier) {
  static const auto& trie = *CreateKeywordInTokenizerTrie().release();
  return trie.Get(identifier) || GetKeywordInfo(identifier);
}

static std::unique_ptr<const CaseInsensitiveAsciiAlphaTrie<const KeywordInfo>>
CreateNonReservedIdentifiersThatMustBeBackquotedTrie() {
  auto trie =
      absl::make_unique<CaseInsensitiveAsciiAlphaTrie<const KeywordInfo>>();
  // These non-reserved keywords are used in the grammar in a location where
  // identifiers also occur, and their meaning is different when they are
  // used without backquoting.
  for (const char* keyword : {
           "access",  // DROP `row` `access` `policy` versus DROP ROW ACCESS
                      // POLICY
           "current_date", "current_datetime", "current_time",
           "current_timestamp", "current_timestamp_micros",
           "current_timestamp_millis", "current_timestamp_seconds", "function",
           "inout",      // See AMBIGUOUS CASE 7 in bison_parser.y
           "out",        // See AMBIGUOUS CASE 7 in bison_parser.y
           "policy",     // DROP `row` `access` `policy` versus DROP ROW ACCESS
                         // POLICY
           "replace",    // INSERT REPLACE versus INSERT `replace`
           "row",        // DROP `row` `access` `policy` versus DROP ROW ACCESS
                         // POLICY
           "safe_cast",  // SAFE_CAST(...) versus `safe_cast`(3)
           "update",     // INSERT UPDATE versus INSERT `update`
           // "value" is not included because it causes too much escaping for
           // this very commonly used name. The impact of this is small. The
           // only place where this can be interpreted as a keyword is in AS
           // VALUE. The alternative interpretation in that case is of a named
           // (protocol buffer) type with name "value". That is unlikely to be
           // an issue in practice. The only risk is that someone can trick a
           // generated query to run as SELECT AS VALUE instead of SELECT AS
           // `VALUE`, which would be very likely to fail and cause type
           // mismatches when it is run.
       }) {
    // We don't care about the KeywordInfo, but we have to create one because
    // the trie needs a non-NULL value. We use an arbitrary bison token.
    KeywordInfo* keyword_info = new KeywordInfo(keyword, KW_SELECT);
    trie->Insert(keyword_info->keyword(), keyword_info);
  }
  return std::move(trie);
}

bool NonReservedIdentifierMustBeBackquoted(absl::string_view identifier) {
  static const auto& trie =
      *CreateNonReservedIdentifiersThatMustBeBackquotedTrie().release();
  return trie.Get(identifier);
}

}  // namespace parser
}  // namespace zetasql
