
#include "souffle/CompiledSouffle.h"

extern "C" {
}

namespace souffle {
using namespace ram;
struct t_btree_2__0_1 {
using t_tuple = Tuple<RamDomain, 2>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_2__0_1& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 2 direct b-tree index [0,1]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_2__0_1__3 {
using t_tuple = Tuple<RamDomain, 2>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_2__0_1__3& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
context h;
return equalRange_3(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 2 direct b-tree index [0,1]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};

class Sf_souffleHOkqI7 : public SouffleProgram {
private:
static inline bool regex_wrapper(const std::string& pattern, const std::string& text) {
   bool result = false; 
   try { result = std::regex_match(text, std::regex(pattern)); } catch(...) { 
     std::cerr << "warning: wrong pattern provided for match(\"" << pattern << "\",\"" << text << "\").\n";
}
   return result;
}
private:
static inline std::string substr_wrapper(const std::string& str, size_t idx, size_t len) {
   std::string result; 
   try { result = str.substr(idx,len); } catch(...) { 
     std::cerr << "warning: wrong index position provided by substr(\"";
     std::cerr << str << "\"," << (int32_t)idx << "," << (int32_t)len << ") functor.\n";
   } return result;
}
private:
static inline RamDomain wrapper_tonumber(const std::string& str) {
   RamDomain result=0; 
   try { result = stord(str); } catch(...) { 
     std::cerr << "error: wrong string provided by to_number(\"";
     std::cerr << str << "\") functor.\n";
     raise(SIGFPE);
   } return result;
}
public:
// -- initialize symbol table --
SymbolTable symTable
{
	R"_(Bot)_",
	R"_(Top)_",
};// -- Table: B
std::unique_ptr<t_btree_2__0_1> rel_1_B = std::make_unique<t_btree_2__0_1>();
souffle::RelationWrapper<0,t_btree_2__0_1,Tuple<RamDomain,2>,2> wrapper_rel_1_B;
// -- Table: C
std::unique_ptr<t_btree_2__0_1> rel_2_C = std::make_unique<t_btree_2__0_1>();
souffle::RelationWrapper<1,t_btree_2__0_1,Tuple<RamDomain,2>,2> wrapper_rel_2_C;
// -- Table: D
std::unique_ptr<t_btree_2__0_1> rel_3_D = std::make_unique<t_btree_2__0_1>();
souffle::RelationWrapper<2,t_btree_2__0_1,Tuple<RamDomain,2>,2> wrapper_rel_3_D;
// -- Table: A
std::unique_ptr<t_btree_2__0_1__3> rel_4_A = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<3,t_btree_2__0_1__3,Tuple<RamDomain,2>,2> wrapper_rel_4_A;
// -- Table: @delta_A
std::unique_ptr<t_btree_2__0_1> rel_5_delta_A = std::make_unique<t_btree_2__0_1>();
// -- Table: @new_A
std::unique_ptr<t_btree_2__0_1> rel_6_new_A = std::make_unique<t_btree_2__0_1>();
// -- Table: R
std::unique_ptr<t_btree_2__0_1__3> rel_7_R = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<4,t_btree_2__0_1__3,Tuple<RamDomain,2>,2> wrapper_rel_7_R;
// -- Table: @delta_R
std::unique_ptr<t_btree_2__0_1> rel_8_delta_R = std::make_unique<t_btree_2__0_1>();
// -- Table: @new_R
std::unique_ptr<t_btree_2__0_1> rel_9_new_R = std::make_unique<t_btree_2__0_1>();
// -- Table: P
std::unique_ptr<t_btree_2__0_1__3> rel_10_P = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<5,t_btree_2__0_1__3,Tuple<RamDomain,2>,2> wrapper_rel_10_P;
// -- Table: @delta_P
std::unique_ptr<t_btree_2__0_1> rel_11_delta_P = std::make_unique<t_btree_2__0_1>();
// -- Table: @new_P
std::unique_ptr<t_btree_2__0_1> rel_12_new_P = std::make_unique<t_btree_2__0_1>();
// -- Table: Q
std::unique_ptr<t_btree_2__0_1__3> rel_13_Q = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<6,t_btree_2__0_1__3,Tuple<RamDomain,2>,2> wrapper_rel_13_Q;
// -- Table: @delta_Q
std::unique_ptr<t_btree_2__0_1__3> rel_14_delta_Q = std::make_unique<t_btree_2__0_1__3>();
// -- Table: @new_Q
std::unique_ptr<t_btree_2__0_1__3> rel_15_new_Q = std::make_unique<t_btree_2__0_1__3>();
// -- Table: S
std::unique_ptr<t_btree_2__0_1__3> rel_16_S = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<7,t_btree_2__0_1__3,Tuple<RamDomain,2>,2> wrapper_rel_16_S;
// -- Table: @delta_S
std::unique_ptr<t_btree_2__0_1> rel_17_delta_S = std::make_unique<t_btree_2__0_1>();
// -- Table: @new_S
std::unique_ptr<t_btree_2__0_1> rel_18_new_S = std::make_unique<t_btree_2__0_1>();
public:
Sf_souffleHOkqI7() : 
wrapper_rel_1_B(*rel_1_B,symTable,"B",std::array<const char *,2>{{"s:symbol","e:Constant{Top:s:symbol,Bot:s:symbol}"}},std::array<const char *,2>{{"x","s"}}),

wrapper_rel_2_C(*rel_2_C,symTable,"C",std::array<const char *,2>{{"s:symbol","e:Constant{Top:s:symbol,Bot:s:symbol}"}},std::array<const char *,2>{{"x","s"}}),

wrapper_rel_3_D(*rel_3_D,symTable,"D",std::array<const char *,2>{{"s:symbol","e:Constant{Top:s:symbol,Bot:s:symbol}"}},std::array<const char *,2>{{"x","s"}}),

wrapper_rel_4_A(*rel_4_A,symTable,"A",std::array<const char *,2>{{"s:symbol","e:Constant{Top:s:symbol,Bot:s:symbol}"}},std::array<const char *,2>{{"x","s"}}),

wrapper_rel_7_R(*rel_7_R,symTable,"R",std::array<const char *,2>{{"s:symbol","e:Constant{Top:s:symbol,Bot:s:symbol}"}},std::array<const char *,2>{{"x","s"}}),

wrapper_rel_10_P(*rel_10_P,symTable,"P",std::array<const char *,2>{{"s:symbol","s:symbol"}},std::array<const char *,2>{{"x","s"}}),

wrapper_rel_13_Q(*rel_13_Q,symTable,"Q",std::array<const char *,2>{{"s:symbol","s:symbol"}},std::array<const char *,2>{{"x","s"}}),

wrapper_rel_16_S(*rel_16_S,symTable,"S",std::array<const char *,2>{{"s:symbol","s:symbol"}},std::array<const char *,2>{{"x","s"}})