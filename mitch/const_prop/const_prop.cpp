
#include "souffle/CompiledSouffle.h"

extern "C" {
}

namespace souffle {
using namespace ram;
struct t_btree_4__0_1_2_3 {
using t_tuple = Tuple<RamDomain, 4>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2,3>>;
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
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_4__0_1_2_3& other) {
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
range<iterator> lattice_range(const t_tuple& _cell) const {
t_tuple cell = _cell;
cell[3] = MIN_RAM_DOMAIN;
auto lower = ind_0.lower_bound(cell);
cell[3] = MAX_RAM_DOMAIN;
auto upper = ind_0.upper_bound(cell);
return make_range(lower, upper);
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 4 direct b-tree index [0,1,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_3__0_1_2 {
using t_tuple = Tuple<RamDomain, 3>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2>>;
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
RamDomain data[3];
std::copy(ramDomain, ramDomain + 3, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2) {
RamDomain data[3] = {a0,a1,a2};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_3__0_1_2& other) {
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
range<iterator> lattice_range(const t_tuple& _cell) const {
t_tuple cell = _cell;
cell[2] = MIN_RAM_DOMAIN;
auto lower = ind_0.lower_bound(cell);
cell[2] = MAX_RAM_DOMAIN;
auto upper = ind_0.upper_bound(cell);
return make_range(lower, upper);
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 3 direct b-tree index [0,1,2]: (hits/misses/total)\n";
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
range<iterator> lattice_range(const t_tuple& _cell) const {
t_tuple cell = _cell;
cell[1] = MIN_RAM_DOMAIN;
auto lower = ind_0.lower_bound(cell);
cell[1] = MAX_RAM_DOMAIN;
auto upper = ind_0.upper_bound(cell);
return make_range(lower, upper);
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
range<iterator> lattice_range(const t_tuple& _cell) const {
t_tuple cell = _cell;
cell[1] = MIN_RAM_DOMAIN;
auto lower = ind_0.lower_bound(cell);
cell[1] = MAX_RAM_DOMAIN;
auto upper = ind_0.upper_bound(cell);
return make_range(lower, upper);
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
struct t_btree_3__0_1_2__7 {
using t_tuple = Tuple<RamDomain, 3>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2>>;
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
RamDomain data[3];
std::copy(ramDomain, ramDomain + 3, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2) {
RamDomain data[3] = {a0,a1,a2};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_3__0_1_2__7& other) {
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
range<t_ind_0::iterator> equalRange_7(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t) const {
context h;
return equalRange_7(t, h);
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
range<iterator> lattice_range(const t_tuple& _cell) const {
t_tuple cell = _cell;
cell[2] = MIN_RAM_DOMAIN;
auto lower = ind_0.lower_bound(cell);
cell[2] = MAX_RAM_DOMAIN;
auto upper = ind_0.upper_bound(cell);
return make_range(lower, upper);
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 3 direct b-tree index [0,1,2]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};

RamDomain luf_lat_alpha(RamDomain);
RamDomain lbf_glb(RamDomain, RamDomain);
RamDomain lbf_lat_div(RamDomain, RamDomain);
RamDomain lbf_lat_minus(RamDomain, RamDomain);
RamDomain lbf_lat_mult(RamDomain, RamDomain);
RamDomain lbf_lat_sum(RamDomain, RamDomain);
RamDomain lbf_lub(RamDomain, RamDomain);

RamDomain luf_lat_alpha(RamDomain arg0) {
  RamDomain args[1] = { arg0 };
return ((args)[0]);
}
RamDomain lbf_glb(RamDomain arg0, RamDomain arg1) {
  RamDomain args[2] = { arg0, arg1 };
if ((((args)[0]) == (RamDomain(2147418111)))) {
return ((args)[1]);
}
if ((((args)[1]) == (RamDomain(2147418111)))) {
return ((args)[0]);
}
return (((((args)[0]) == ((args)[1]))) ? ((args)[0]) : (RamDomain(2147418112)));
}
RamDomain lbf_lat_div(RamDomain arg0, RamDomain arg1) {
  RamDomain args[2] = { arg0, arg1 };
if ((((args)[0]) == (RamDomain(2147418112)))) {
return (RamDomain(2147418112));
}
if ((((args)[1]) == (RamDomain(2147418112)))) {
return (RamDomain(2147418112));
}
if ((((args)[0]) == (RamDomain(2147418111)))) {
return (RamDomain(2147418111));
}
if ((((args)[1]) == (RamDomain(2147418111)))) {
return (RamDomain(2147418111));
}
return (((args)[0]) / ((args)[1]));
}
RamDomain lbf_lat_minus(RamDomain arg0, RamDomain arg1) {
  RamDomain args[2] = { arg0, arg1 };
if ((((args)[0]) == (RamDomain(2147418112)))) {
return (RamDomain(2147418112));
}
if ((((args)[1]) == (RamDomain(2147418112)))) {
return (RamDomain(2147418112));
}
if ((((args)[0]) == (RamDomain(2147418111)))) {
return (RamDomain(2147418111));
}
if ((((args)[1]) == (RamDomain(2147418111)))) {
return (RamDomain(2147418111));
}
return (((args)[0]) - ((args)[1]));
}
RamDomain lbf_lat_mult(RamDomain arg0, RamDomain arg1) {
  RamDomain args[2] = { arg0, arg1 };
if ((((args)[0]) == (RamDomain(2147418112)))) {
return (RamDomain(2147418112));
}
if ((((args)[1]) == (RamDomain(2147418112)))) {
return (RamDomain(2147418112));
}
if ((((args)[0]) == (RamDomain(2147418111)))) {
return (RamDomain(2147418111));
}
if ((((args)[1]) == (RamDomain(2147418111)))) {
return (RamDomain(2147418111));
}
return (((args)[0]) * ((args)[1]));
}
RamDomain lbf_lat_sum(RamDomain arg0, RamDomain arg1) {
  RamDomain args[2] = { arg0, arg1 };
if ((((args)[0]) == (RamDomain(2147418112)))) {
return (RamDomain(2147418112));
}
if ((((args)[1]) == (RamDomain(2147418112)))) {
return (RamDomain(2147418112));
}
if ((((args)[0]) == (RamDomain(2147418111)))) {
return (RamDomain(2147418111));
}
if ((((args)[1]) == (RamDomain(2147418111)))) {
return (RamDomain(2147418111));
}
return (((args)[0]) + ((args)[1]));
}
RamDomain lbf_lub(RamDomain arg0, RamDomain arg1) {
  RamDomain args[2] = { arg0, arg1 };
if ((((args)[0]) == (RamDomain(2147418112)))) {
return ((args)[1]);
}
if ((((args)[1]) == (RamDomain(2147418112)))) {
return ((args)[0]);
}
return (((((args)[0]) == ((args)[1]))) ? ((args)[0]) : (RamDomain(2147418111)));
}
class Sf_const_prop : public SouffleProgram {
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
	std::make_pair(R"_(Bot)_",2147418112),
	std::make_pair(R"_(Top)_",2147418111),
};// -- Table: addStm
std::unique_ptr<t_btree_4__0_1_2_3> rel_1_addStm = std::make_unique<t_btree_4__0_1_2_3>();
souffle::RelationWrapper<0,t_btree_4__0_1_2_3,Tuple<RamDomain,4>,4> wrapper_rel_1_addStm;
// -- Table: divStm
std::unique_ptr<t_btree_4__0_1_2_3> rel_2_divStm = std::make_unique<t_btree_4__0_1_2_3>();
souffle::RelationWrapper<1,t_btree_4__0_1_2_3,Tuple<RamDomain,4>,4> wrapper_rel_2_divStm;
// -- Table: minusStm
std::unique_ptr<t_btree_4__0_1_2_3> rel_3_minusStm = std::make_unique<t_btree_4__0_1_2_3>();
souffle::RelationWrapper<2,t_btree_4__0_1_2_3,Tuple<RamDomain,4>,4> wrapper_rel_3_minusStm;
// -- Table: multStm
std::unique_ptr<t_btree_4__0_1_2_3> rel_4_multStm = std::make_unique<t_btree_4__0_1_2_3>();
souffle::RelationWrapper<3,t_btree_4__0_1_2_3,Tuple<RamDomain,4>,4> wrapper_rel_4_multStm;
// -- Table: setConstStm
std::unique_ptr<t_btree_3__0_1_2> rel_5_setConstStm = std::make_unique<t_btree_3__0_1_2>();
souffle::RelationWrapper<4,t_btree_3__0_1_2,Tuple<RamDomain,3>,3> wrapper_rel_5_setConstStm;
// -- Table: assignVar
std::unique_ptr<t_btree_2__0_1__3> rel_6_assignVar = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<5,t_btree_2__0_1__3,Tuple<RamDomain,2>,2> wrapper_rel_6_assignVar;
// -- Table: flow
std::unique_ptr<t_btree_2__0_1> rel_7_flow = std::make_unique<t_btree_2__0_1>();
souffle::RelationWrapper<6,t_btree_2__0_1,Tuple<RamDomain,2>,2> wrapper_rel_7_flow;
// -- Table: varEntry
std::unique_ptr<t_btree_3__0_1_2__7> rel_8_varEntry = std::make_unique<t_btree_3__0_1_2__7>();
souffle::RelationWrapper<7,t_btree_3__0_1_2__7,Tuple<RamDomain,3>,3> wrapper_rel_8_varEntry;
// -- Table: @delta_varEntry
std::unique_ptr<t_btree_3__0_1_2__7> rel_9_delta_varEntry = std::make_unique<t_btree_3__0_1_2__7>();
// -- Table: @new_varEntry
std::unique_ptr<t_btree_3__0_1_2__7> rel_10_new_varEntry = std::make_unique<t_btree_3__0_1_2__7>();
// -- Table: @org_lat_varEntry
std::unique_ptr<t_btree_3__0_1_2__7> rel_11_org_lat_varEntry = std::make_unique<t_btree_3__0_1_2__7>();
// -- Table: @new_lat_varEntry
std::unique_ptr<t_btree_3__0_1_2__7> rel_12_new_lat_varEntry = std::make_unique<t_btree_3__0_1_2__7>();
// -- Table: varExit
std::unique_ptr<t_btree_3__0_1_2__7> rel_13_varExit = std::make_unique<t_btree_3__0_1_2__7>();
souffle::RelationWrapper<8,t_btree_3__0_1_2__7,Tuple<RamDomain,3>,3> wrapper_rel_13_varExit;
// -- Table: @delta_varExit
std::unique_ptr<t_btree_3__0_1_2> rel_14_delta_varExit = std::make_unique<t_btree_3__0_1_2>();
// -- Table: @new_varExit
std::unique_ptr<t_btree_3__0_1_2> rel_15_new_varExit = std::make_unique<t_btree_3__0_1_2>();
// -- Table: @org_lat_varExit
std::unique_ptr<t_btree_3__0_1_2__7> rel_16_org_lat_varExit = std::make_unique<t_btree_3__0_1_2__7>();
// -- Table: @new_lat_varExit
std::unique_ptr<t_btree_3__0_1_2> rel_17_new_lat_varExit = std::make_unique<t_btree_3__0_1_2>();
// -- Table: @lat_temp_varExit
std::unique_ptr<t_btree_3__0_1_2__7> rel_18_lat_temp_varExit = std::make_unique<t_btree_3__0_1_2__7>();
public:
Sf_const_prop() : 
wrapper_rel_1_addStm(*rel_1_addStm,symTable,"addStm",std::array<const char *,4>{{"i:number","s:symbol","s:symbol","s:symbol"}},std::array<const char *,4>{{"l","r","x","y"}}),

wrapper_rel_2_divStm(*rel_2_divStm,symTable,"divStm",std::array<const char *,4>{{"i:number","s:symbol","s:symbol","s:symbol"}},std::array<const char *,4>{{"l","r","x","y"}}),

wrapper_rel_3_minusStm(*rel_3_minusStm,symTable,"minusStm",std::array<const char *,4>{{"i:number","s:symbol","s:symbol","s:symbol"}},std::array<const char *,4>{{"l","r","x","y"}}),

wrapper_rel_4_multStm(*rel_4_multStm,symTable,"multStm",std::array<const char *,4>{{"i:number","s:symbol","s:symbol","s:symbol"}},std::array<const char *,4>{{"l","r","x","y"}}),

wrapper_rel_5_setConstStm(*rel_5_setConstStm,symTable,"setConstStm",std::array<const char *,3>{{"i:number","s:symbol","i:number"}},std::array<const char *,3>{{"l","r","c"}}),

wrapper_rel_6_assignVar(*rel_6_assignVar,symTable,"assignVar",std::array<const char *,2>{{"i:number","s:symbol"}},std::array<const char *,2>{{"l","r"}}),

wrapper_rel_7_flow(*rel_7_flow,symTable,"flow",std::array<const char *,2>{{"i:number","i:number"}},std::array<const char *,2>{{"l1","l2"}}),

wrapper_rel_8_varEntry(*rel_8_varEntry,symTable,"varEntry",std::array<const char *,3>{{"i:number","s:symbol","e:Constant{Top:s:symbol,Bot:s:symbol}"}},std::array<const char *,3>{{"l","k","v"}}),

wrapper_rel_13_varExit(*rel_13_varExit,symTable,"varExit",std::array<const char *,3>{{"i:number","s:symbol","e:Constant{Top:s:symbol,Bot:s:symbol}"}},std::array<const char *,3>{{"l","k","v"}}){
addRelation("addStm",&wrapper_rel_1_addStm,true,false);
addRelation("divStm",&wrapper_rel_2_divStm,true,false);
addRelation("minusStm",&wrapper_rel_3_minusStm,true,false);
addRelation("multStm",&wrapper_rel_4_multStm,true,false);
addRelation("setConstStm",&wrapper_rel_5_setConstStm,true,false);
addRelation("assignVar",&wrapper_rel_6_assignVar,false,false);
addRelation("flow",&wrapper_rel_7_flow,true,false);
addRelation("varEntry",&wrapper_rel_8_varEntry,true,true);
addRelation("varExit",&wrapper_rel_13_varExit,false,true);
}
~Sf_const_prop() {
}
private:
void runFunction(std::string inputDirectory = ".", std::string outputDirectory = ".", size_t stratumIndex = (size_t) -1, bool performIO = false) {
SignalHandler::instance()->set();
std::atomic<size_t> iter(0);

#if defined(__EMBEDDED_SOUFFLE__) && defined(_OPENMP)
omp_set_num_threads(8);
#endif

// -- query evaluation --
/* BEGIN STRATUM 0 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/addStm.facts"},{"name","addStm"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 1, 1, 1}), EnumTypeMask({0, 0, 0, 0}), symTable, ioDirectives, 0)->readAll(*rel_1_addStm);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/divStm.facts"},{"name","divStm"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 1, 1, 1}), EnumTypeMask({0, 0, 0, 0}), symTable, ioDirectives, 0)->readAll(*rel_2_divStm);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/minusStm.facts"},{"name","minusStm"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 1, 1, 1}), EnumTypeMask({0, 0, 0, 0}), symTable, ioDirectives, 0)->readAll(*rel_3_minusStm);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/multStm.facts"},{"name","multStm"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 1, 1, 1}), EnumTypeMask({0, 0, 0, 0}), symTable, ioDirectives, 0)->readAll(*rel_4_multStm);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/setConstStm.facts"},{"name","setConstStm"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 1, 0}), EnumTypeMask({0, 0, 0}), symTable, ioDirectives, 0)->readAll(*rel_5_setConstStm);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
SignalHandler::instance()->setMsg(R"_(assignVar(l,r) :- 
   setConstStm(l,r,_).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [83:1-83:41])_");
if (!rel_5_setConstStm->empty()) [&](){
auto part = rel_5_setConstStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_6_assignVar_op_ctxt,rel_6_assignVar->createContext());
CREATE_OP_CONTEXT(rel_5_setConstStm_op_ctxt,rel_5_setConstStm->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}});
rel_6_assignVar->insert(tuple,READ_OP_CONTEXT(rel_6_assignVar_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(assignVar(l,r) :- 
   addStm(l,r,_,_).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [84:1-84:39])_");
if (!rel_1_addStm->empty()) [&](){
auto part = rel_1_addStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_addStm_op_ctxt,rel_1_addStm->createContext());
CREATE_OP_CONTEXT(rel_6_assignVar_op_ctxt,rel_6_assignVar->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}});
rel_6_assignVar->insert(tuple,READ_OP_CONTEXT(rel_6_assignVar_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(assignVar(l,r) :- 
   minusStm(l,r,_,_).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [85:1-85:41])_");
if (!rel_3_minusStm->empty()) [&](){
auto part = rel_3_minusStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_6_assignVar_op_ctxt,rel_6_assignVar->createContext());
CREATE_OP_CONTEXT(rel_3_minusStm_op_ctxt,rel_3_minusStm->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}});
rel_6_assignVar->insert(tuple,READ_OP_CONTEXT(rel_6_assignVar_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(assignVar(l,r) :- 
   multStm(l,r,_,_).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [86:1-86:40])_");
if (!rel_4_multStm->empty()) [&](){
auto part = rel_4_multStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_6_assignVar_op_ctxt,rel_6_assignVar->createContext());
CREATE_OP_CONTEXT(rel_4_multStm_op_ctxt,rel_4_multStm->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}});
rel_6_assignVar->insert(tuple,READ_OP_CONTEXT(rel_6_assignVar_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(assignVar(l,r) :- 
   divStm(l,r,_,_).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [87:1-87:39])_");
if (!rel_2_divStm->empty()) [&](){
auto part = rel_2_divStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_6_assignVar_op_ctxt,rel_6_assignVar->createContext());
CREATE_OP_CONTEXT(rel_2_divStm_op_ctxt,rel_2_divStm->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1])}});
rel_6_assignVar->insert(tuple,READ_OP_CONTEXT(rel_6_assignVar_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/flow.facts"},{"name","flow"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 0}), EnumTypeMask({0, 0}), symTable, ioDirectives, 0)->readAll(*rel_7_flow);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 6 */
/* BEGIN STRATUM 7 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/varEntry.facts"},{"name","varEntry"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 1, 0}), EnumTypeMask({0, 0, 1}), symTable, ioDirectives, 0)->readAll(*rel_8_varEntry);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
rel_9_delta_varEntry->insertAll(*rel_8_varEntry);
SignalHandler::instance()->setMsg(R"_(varExit(l,r,&lat_alpha(c)) :- 
   setConstStm(l,r,c).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [96:1-96:54])_");
if (!rel_5_setConstStm->empty()) [&](){
auto part = rel_5_setConstStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_5_setConstStm_op_ctxt,rel_5_setConstStm->createContext());
CREATE_OP_CONTEXT(rel_13_varExit_op_ctxt,rel_13_varExit->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,3> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(luf_lat_alpha(env0[2]))}});
rel_13_varExit->insert(tuple,READ_OP_CONTEXT(rel_13_varExit_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();// LatNorm
if (!rel_13_varExit->empty()) {
Tuple<RamDomain, 3> latti_cell;
bool latti_first = true;
RamDomain latti_lub;
for(auto it = rel_13_varExit->begin(); it != rel_13_varExit->end();) {
const auto& entry = *it;
bool latti_newcell = latti_first;
for(int i = 0; i < 2; i++){
if (latti_cell[i] != entry[i]) {
latti_cell[i] = entry[i]; latti_newcell=true;
}
}
if (latti_newcell) {
latti_lub = RamDomain(2147418112);
for (; it != rel_13_varExit->end(); ++it) {
const auto& entry2 = *it;
latti_newcell = false;
for(int i = 0; i < 2; i++){
if (latti_cell[i] != entry2[i]) {
latti_newcell=true;
}
}
if (!latti_newcell) {
latti_lub = lbf_lub(latti_lub, entry2[2]);
} else {
break;
}
}
latti_cell[2] = latti_lub;
rel_18_lat_temp_varExit->insert(latti_cell);
} else {
++it;
}
latti_first = false;
}
}
std::swap(rel_13_varExit, rel_18_lat_temp_varExit);
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_18_lat_temp_varExit->purge();
rel_14_delta_varExit->insertAll(*rel_13_varExit);
iter = 0;
for(;;) {
SECTIONS_START;
SECTION_START;
SignalHandler::instance()->setMsg(R"_(varEntry(l2,k,v) :- 
   varExit(l1,k,v),
   flow(l1,l2).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [93:1-93:55])_");
if (!rel_14_delta_varExit->empty()&&!rel_7_flow->empty()) [&](){
auto part = rel_14_delta_varExit->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_14_delta_varExit_op_ctxt,rel_14_delta_varExit->createContext());
CREATE_OP_CONTEXT(rel_10_new_varEntry_op_ctxt,rel_10_new_varEntry->createContext());
CREATE_OP_CONTEXT(rel_7_flow_op_ctxt,rel_7_flow->createContext());
CREATE_OP_CONTEXT(rel_8_varEntry_op_ctxt,rel_8_varEntry->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
for(const auto& env1 : *rel_7_flow) {
if( !(rel_8_varEntry->contains(Tuple<RamDomain,3>({{env1[1],env0[1],env0[2]}}),READ_OP_CONTEXT(rel_8_varEntry_op_ctxt)))) {
if( ((env0[0]) == (env1[0]))) {
Tuple<RamDomain,3> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2])}});
rel_10_new_varEntry->insert(tuple,READ_OP_CONTEXT(rel_10_new_varEntry_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SECTION_END
SECTION_START;
SignalHandler::instance()->setMsg(R"_(varExit(l,r,&lat_sum(v1,v2)) :- 
   addStm(l,r,x,y),
   varEntry(l,x,v1),
   varEntry(l,y,v2).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [100:1-102:48])_");
if (!rel_9_delta_varEntry->empty()&&!rel_1_addStm->empty()&&!rel_8_varEntry->empty()) [&](){
auto part = rel_1_addStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_9_delta_varEntry_op_ctxt,rel_9_delta_varEntry->createContext());
CREATE_OP_CONTEXT(rel_15_new_varExit_op_ctxt,rel_15_new_varExit->createContext());
CREATE_OP_CONTEXT(rel_1_addStm_op_ctxt,rel_1_addStm->createContext());
CREATE_OP_CONTEXT(rel_8_varEntry_op_ctxt,rel_8_varEntry->createContext());
CREATE_OP_CONTEXT(rel_13_varExit_op_ctxt,rel_13_varExit->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
for(const auto& env1 : *rel_9_delta_varEntry) {
for(const auto& env2 : *rel_8_varEntry) {
if( !(rel_9_delta_varEntry->contains(Tuple<RamDomain,3>({{env0[0],env0[3],env2[2]}}),READ_OP_CONTEXT(rel_9_delta_varEntry_op_ctxt)))) {
if( !(rel_13_varExit->contains(Tuple<RamDomain,3>({{env0[0],env0[1],lbf_lat_sum(env1[2],env2[2])}}),READ_OP_CONTEXT(rel_13_varExit_op_ctxt)))) {
if( ((env0[3]) == (env2[1]))) {
if( ((env0[2]) == (env1[1]))) {
if( ((env0[0]) == (env2[0]))) {
if( ((env0[0]) == (env1[0]))) {
Tuple<RamDomain,3> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(lbf_lat_sum(env1[2],env2[2]))}});
rel_15_new_varExit->insert(tuple,READ_OP_CONTEXT(rel_15_new_varExit_op_ctxt));
}
}
}
}
}
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(varExit(l,r,&lat_sum(v1,v2)) :- 
   addStm(l,r,x,y),
   varEntry(l,x,v1),
   varEntry(l,y,v2).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [100:1-102:48])_");
if (!rel_9_delta_varEntry->empty()&&!rel_1_addStm->empty()&&!rel_8_varEntry->empty()) [&](){
auto part = rel_1_addStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_9_delta_varEntry_op_ctxt,rel_9_delta_varEntry->createContext());
CREATE_OP_CONTEXT(rel_15_new_varExit_op_ctxt,rel_15_new_varExit->createContext());
CREATE_OP_CONTEXT(rel_1_addStm_op_ctxt,rel_1_addStm->createContext());
CREATE_OP_CONTEXT(rel_8_varEntry_op_ctxt,rel_8_varEntry->createContext());
CREATE_OP_CONTEXT(rel_13_varExit_op_ctxt,rel_13_varExit->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_varEntry) {
for(const auto& env2 : *rel_9_delta_varEntry) {
if( !(rel_13_varExit->contains(Tuple<RamDomain,3>({{env0[0],env0[1],lbf_lat_sum(env1[2],env2[2])}}),READ_OP_CONTEXT(rel_13_varExit_op_ctxt)))) {
if( ((env0[3]) == (env2[1]))) {
if( ((env0[2]) == (env1[1]))) {
if( ((env0[0]) == (env2[0]))) {
if( ((env0[0]) == (env1[0]))) {
Tuple<RamDomain,3> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(lbf_lat_sum(env1[2],env2[2]))}});
rel_15_new_varExit->insert(tuple,READ_OP_CONTEXT(rel_15_new_varExit_op_ctxt));
}
}
}
}
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(varExit(l,r,&lat_minus(v1,v2)) :- 
   minusStm(l,r,x,y),
   varEntry(l,x,v1),
   varEntry(l,y,v2).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [104:1-106:48])_");
if (!rel_9_delta_varEntry->empty()&&!rel_3_minusStm->empty()&&!rel_8_varEntry->empty()) [&](){
auto part = rel_3_minusStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_9_delta_varEntry_op_ctxt,rel_9_delta_varEntry->createContext());
CREATE_OP_CONTEXT(rel_15_new_varExit_op_ctxt,rel_15_new_varExit->createContext());
CREATE_OP_CONTEXT(rel_3_minusStm_op_ctxt,rel_3_minusStm->createContext());
CREATE_OP_CONTEXT(rel_8_varEntry_op_ctxt,rel_8_varEntry->createContext());
CREATE_OP_CONTEXT(rel_13_varExit_op_ctxt,rel_13_varExit->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
for(const auto& env1 : *rel_9_delta_varEntry) {
for(const auto& env2 : *rel_8_varEntry) {
if( !(rel_9_delta_varEntry->contains(Tuple<RamDomain,3>({{env0[0],env0[3],env2[2]}}),READ_OP_CONTEXT(rel_9_delta_varEntry_op_ctxt)))) {
if( !(rel_13_varExit->contains(Tuple<RamDomain,3>({{env0[0],env0[1],lbf_lat_minus(env1[2],env2[2])}}),READ_OP_CONTEXT(rel_13_varExit_op_ctxt)))) {
if( ((env0[3]) == (env2[1]))) {
if( ((env0[2]) == (env1[1]))) {
if( ((env0[0]) == (env2[0]))) {
if( ((env0[0]) == (env1[0]))) {
Tuple<RamDomain,3> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(lbf_lat_minus(env1[2],env2[2]))}});
rel_15_new_varExit->insert(tuple,READ_OP_CONTEXT(rel_15_new_varExit_op_ctxt));
}
}
}
}
}
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(varExit(l,r,&lat_minus(v1,v2)) :- 
   minusStm(l,r,x,y),
   varEntry(l,x,v1),
   varEntry(l,y,v2).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [104:1-106:48])_");
if (!rel_9_delta_varEntry->empty()&&!rel_3_minusStm->empty()&&!rel_8_varEntry->empty()) [&](){
auto part = rel_3_minusStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_9_delta_varEntry_op_ctxt,rel_9_delta_varEntry->createContext());
CREATE_OP_CONTEXT(rel_15_new_varExit_op_ctxt,rel_15_new_varExit->createContext());
CREATE_OP_CONTEXT(rel_3_minusStm_op_ctxt,rel_3_minusStm->createContext());
CREATE_OP_CONTEXT(rel_8_varEntry_op_ctxt,rel_8_varEntry->createContext());
CREATE_OP_CONTEXT(rel_13_varExit_op_ctxt,rel_13_varExit->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_varEntry) {
for(const auto& env2 : *rel_9_delta_varEntry) {
if( !(rel_13_varExit->contains(Tuple<RamDomain,3>({{env0[0],env0[1],lbf_lat_minus(env1[2],env2[2])}}),READ_OP_CONTEXT(rel_13_varExit_op_ctxt)))) {
if( ((env0[3]) == (env2[1]))) {
if( ((env0[2]) == (env1[1]))) {
if( ((env0[0]) == (env2[0]))) {
if( ((env0[0]) == (env1[0]))) {
Tuple<RamDomain,3> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(lbf_lat_minus(env1[2],env2[2]))}});
rel_15_new_varExit->insert(tuple,READ_OP_CONTEXT(rel_15_new_varExit_op_ctxt));
}
}
}
}
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(varExit(l,r,&lat_mult(v1,v2)) :- 
   multStm(l,r,x,y),
   varEntry(l,x,v1),
   varEntry(l,y,v2).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [108:1-110:48])_");
if (!rel_9_delta_varEntry->empty()&&!rel_4_multStm->empty()&&!rel_8_varEntry->empty()) [&](){
auto part = rel_4_multStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_9_delta_varEntry_op_ctxt,rel_9_delta_varEntry->createContext());
CREATE_OP_CONTEXT(rel_15_new_varExit_op_ctxt,rel_15_new_varExit->createContext());
CREATE_OP_CONTEXT(rel_4_multStm_op_ctxt,rel_4_multStm->createContext());
CREATE_OP_CONTEXT(rel_8_varEntry_op_ctxt,rel_8_varEntry->createContext());
CREATE_OP_CONTEXT(rel_13_varExit_op_ctxt,rel_13_varExit->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
for(const auto& env1 : *rel_9_delta_varEntry) {
for(const auto& env2 : *rel_8_varEntry) {
if( !(rel_9_delta_varEntry->contains(Tuple<RamDomain,3>({{env0[0],env0[3],env2[2]}}),READ_OP_CONTEXT(rel_9_delta_varEntry_op_ctxt)))) {
if( !(rel_13_varExit->contains(Tuple<RamDomain,3>({{env0[0],env0[1],lbf_lat_mult(env1[2],env2[2])}}),READ_OP_CONTEXT(rel_13_varExit_op_ctxt)))) {
if( ((env0[3]) == (env2[1]))) {
if( ((env0[2]) == (env1[1]))) {
if( ((env0[0]) == (env2[0]))) {
if( ((env0[0]) == (env1[0]))) {
Tuple<RamDomain,3> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(lbf_lat_mult(env1[2],env2[2]))}});
rel_15_new_varExit->insert(tuple,READ_OP_CONTEXT(rel_15_new_varExit_op_ctxt));
}
}
}
}
}
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(varExit(l,r,&lat_mult(v1,v2)) :- 
   multStm(l,r,x,y),
   varEntry(l,x,v1),
   varEntry(l,y,v2).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [108:1-110:48])_");
if (!rel_9_delta_varEntry->empty()&&!rel_4_multStm->empty()&&!rel_8_varEntry->empty()) [&](){
auto part = rel_4_multStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_9_delta_varEntry_op_ctxt,rel_9_delta_varEntry->createContext());
CREATE_OP_CONTEXT(rel_15_new_varExit_op_ctxt,rel_15_new_varExit->createContext());
CREATE_OP_CONTEXT(rel_4_multStm_op_ctxt,rel_4_multStm->createContext());
CREATE_OP_CONTEXT(rel_8_varEntry_op_ctxt,rel_8_varEntry->createContext());
CREATE_OP_CONTEXT(rel_13_varExit_op_ctxt,rel_13_varExit->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_varEntry) {
for(const auto& env2 : *rel_9_delta_varEntry) {
if( !(rel_13_varExit->contains(Tuple<RamDomain,3>({{env0[0],env0[1],lbf_lat_mult(env1[2],env2[2])}}),READ_OP_CONTEXT(rel_13_varExit_op_ctxt)))) {
if( ((env0[3]) == (env2[1]))) {
if( ((env0[2]) == (env1[1]))) {
if( ((env0[0]) == (env2[0]))) {
if( ((env0[0]) == (env1[0]))) {
Tuple<RamDomain,3> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(lbf_lat_mult(env1[2],env2[2]))}});
rel_15_new_varExit->insert(tuple,READ_OP_CONTEXT(rel_15_new_varExit_op_ctxt));
}
}
}
}
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(varExit(l,r,v) :- 
   varEntry(l,r,v),
   !assignVar(l,r).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [117:1-117:57])_");
if (!rel_9_delta_varEntry->empty()) [&](){
auto part = rel_9_delta_varEntry->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_9_delta_varEntry_op_ctxt,rel_9_delta_varEntry->createContext());
CREATE_OP_CONTEXT(rel_15_new_varExit_op_ctxt,rel_15_new_varExit->createContext());
CREATE_OP_CONTEXT(rel_6_assignVar_op_ctxt,rel_6_assignVar->createContext());
CREATE_OP_CONTEXT(rel_13_varExit_op_ctxt,rel_13_varExit->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
if( !(rel_13_varExit->contains(Tuple<RamDomain,3>({{env0[0],env0[1],env0[2]}}),READ_OP_CONTEXT(rel_13_varExit_op_ctxt)))) {
if( !(rel_6_assignVar->contains(Tuple<RamDomain,2>({{env0[0],env0[1]}}),READ_OP_CONTEXT(rel_6_assignVar_op_ctxt)))) {
Tuple<RamDomain,3> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(env0[2])}});
rel_15_new_varExit->insert(tuple,READ_OP_CONTEXT(rel_15_new_varExit_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(varExit(l,r,&lat_div(v1,v2)) :- 
   divStm(l,r,x,y),
   varEntry(l,x,v1),
   varEntry(l,y,v2),
   v2 != &lat_alpha(0).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [112:1-114:67])_");
if (!rel_9_delta_varEntry->empty()&&!rel_2_divStm->empty()&&!rel_8_varEntry->empty()) [&](){
auto part = rel_2_divStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_9_delta_varEntry_op_ctxt,rel_9_delta_varEntry->createContext());
CREATE_OP_CONTEXT(rel_15_new_varExit_op_ctxt,rel_15_new_varExit->createContext());
CREATE_OP_CONTEXT(rel_2_divStm_op_ctxt,rel_2_divStm->createContext());
CREATE_OP_CONTEXT(rel_8_varEntry_op_ctxt,rel_8_varEntry->createContext());
CREATE_OP_CONTEXT(rel_13_varExit_op_ctxt,rel_13_varExit->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
for(const auto& env1 : *rel_9_delta_varEntry) {
for(const auto& env2 : *rel_8_varEntry) {
if( ((env2[2]) != (luf_lat_alpha(RamDomain(0))))) {
if( !(rel_9_delta_varEntry->contains(Tuple<RamDomain,3>({{env0[0],env0[3],env2[2]}}),READ_OP_CONTEXT(rel_9_delta_varEntry_op_ctxt)))) {
if( !(rel_13_varExit->contains(Tuple<RamDomain,3>({{env0[0],env0[1],lbf_lat_div(env1[2],env2[2])}}),READ_OP_CONTEXT(rel_13_varExit_op_ctxt)))) {
if( ((env0[3]) == (env2[1]))) {
if( ((env0[2]) == (env1[1]))) {
if( ((env0[0]) == (env2[0]))) {
if( ((env0[0]) == (env1[0]))) {
Tuple<RamDomain,3> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(lbf_lat_div(env1[2],env2[2]))}});
rel_15_new_varExit->insert(tuple,READ_OP_CONTEXT(rel_15_new_varExit_op_ctxt));
}
}
}
}
}
}
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(varExit(l,r,&lat_div(v1,v2)) :- 
   divStm(l,r,x,y),
   varEntry(l,x,v1),
   varEntry(l,y,v2),
   v2 != &lat_alpha(0).
in file /home/doublemix/workspace/souffle-qxg2/mitch/const_prop/const_prop.dl [112:1-114:67])_");
if (!rel_9_delta_varEntry->empty()&&!rel_2_divStm->empty()&&!rel_8_varEntry->empty()) [&](){
auto part = rel_2_divStm->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_9_delta_varEntry_op_ctxt,rel_9_delta_varEntry->createContext());
CREATE_OP_CONTEXT(rel_15_new_varExit_op_ctxt,rel_15_new_varExit->createContext());
CREATE_OP_CONTEXT(rel_2_divStm_op_ctxt,rel_2_divStm->createContext());
CREATE_OP_CONTEXT(rel_8_varEntry_op_ctxt,rel_8_varEntry->createContext());
CREATE_OP_CONTEXT(rel_13_varExit_op_ctxt,rel_13_varExit->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_varEntry) {
for(const auto& env2 : *rel_9_delta_varEntry) {
if( ((env2[2]) != (luf_lat_alpha(RamDomain(0))))) {
if( !(rel_13_varExit->contains(Tuple<RamDomain,3>({{env0[0],env0[1],lbf_lat_div(env1[2],env2[2])}}),READ_OP_CONTEXT(rel_13_varExit_op_ctxt)))) {
if( ((env0[3]) == (env2[1]))) {
if( ((env0[2]) == (env1[1]))) {
if( ((env0[0]) == (env2[0]))) {
if( ((env0[0]) == (env1[0]))) {
Tuple<RamDomain,3> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(env0[1]),static_cast<RamDomain>(lbf_lat_div(env1[2],env2[2]))}});
rel_15_new_varExit->insert(tuple,READ_OP_CONTEXT(rel_15_new_varExit_op_ctxt));
}
}
}
}
}
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SECTION_END
SECTIONS_END;
// LatClean
if (!rel_10_new_varEntry->empty()) {
Tuple<RamDomain, 3> latti_cell;
bool latti_first = true;
RamDomain latti_lub;
for(auto it = rel_10_new_varEntry->begin(); it != rel_10_new_varEntry->end();) {
const auto& entry = *it;
bool latti_newcell = latti_first;
for(int i = 0; i < 2; i++){
if (latti_cell[i] != entry[i]) {
latti_cell[i] = entry[i]; latti_newcell=true;
}
}
if (latti_newcell) {
latti_lub = RamDomain(2147418112);
auto latti_range = rel_8_varEntry->lattice_range(latti_cell);
for(auto idx = latti_range.begin(); idx != latti_range.end(); ++idx) {
latti_lub = lbf_lub(latti_lub, (*idx)[2]);
}
for (; it != rel_10_new_varEntry->end(); ++it) {
const auto& entry2 = *it;
latti_newcell = false;
for(int i = 0; i < 2; i++){
if (latti_cell[i] != entry2[i]) {
latti_newcell=true;
}
}
if (!latti_newcell) {
latti_lub = lbf_lub(latti_lub, entry2[2]);
} else {
break;
}
}
latti_cell[2] = latti_lub;
if (!rel_8_varEntry->contains(latti_cell)) {
rel_12_new_lat_varEntry->insert(latti_cell);
}
} else {
++it;
}
latti_first = false;
}
}
std::swap(rel_10_new_varEntry, rel_12_new_lat_varEntry);
rel_12_new_lat_varEntry->purge();
// LatClean
if (!rel_15_new_varExit->empty()) {
Tuple<RamDomain, 3> latti_cell;
bool latti_first = true;
RamDomain latti_lub;
for(auto it = rel_15_new_varExit->begin(); it != rel_15_new_varExit->end();) {
const auto& entry = *it;
bool latti_newcell = latti_first;
for(int i = 0; i < 2; i++){
if (latti_cell[i] != entry[i]) {
latti_cell[i] = entry[i]; latti_newcell=true;
}
}
if (latti_newcell) {
latti_lub = RamDomain(2147418112);
auto latti_range = rel_13_varExit->lattice_range(latti_cell);
for(auto idx = latti_range.begin(); idx != latti_range.end(); ++idx) {
latti_lub = lbf_lub(latti_lub, (*idx)[2]);
}
for (; it != rel_15_new_varExit->end(); ++it) {
const auto& entry2 = *it;
latti_newcell = false;
for(int i = 0; i < 2; i++){
if (latti_cell[i] != entry2[i]) {
latti_newcell=true;
}
}
if (!latti_newcell) {
latti_lub = lbf_lub(latti_lub, entry2[2]);
} else {
break;
}
}
latti_cell[2] = latti_lub;
if (!rel_13_varExit->contains(latti_cell)) {
rel_17_new_lat_varExit->insert(latti_cell);
}
} else {
++it;
}
latti_first = false;
}
}
std::swap(rel_15_new_varExit, rel_17_new_lat_varExit);
rel_17_new_lat_varExit->purge();
if(((rel_10_new_varEntry->empty()) && (rel_15_new_varExit->empty()))) break;
rel_8_varEntry->insertAll(*rel_10_new_varEntry);
std::swap(rel_9_delta_varEntry, rel_10_new_varEntry);
rel_10_new_varEntry->purge();
rel_13_varExit->insertAll(*rel_15_new_varExit);
std::swap(rel_14_delta_varExit, rel_15_new_varExit);
rel_15_new_varExit->purge();
iter++;
}
iter = 0;
// LatNorm
if (!rel_8_varEntry->empty()) {
Tuple<RamDomain, 3> latti_cell;
bool latti_first = true;
RamDomain latti_lub;
for(auto it = rel_8_varEntry->begin(); it != rel_8_varEntry->end();) {
const auto& entry = *it;
bool latti_newcell = latti_first;
for(int i = 0; i < 2; i++){
if (latti_cell[i] != entry[i]) {
latti_cell[i] = entry[i]; latti_newcell=true;
}
}
if (latti_newcell) {
latti_lub = RamDomain(2147418112);
for (; it != rel_8_varEntry->end(); ++it) {
const auto& entry2 = *it;
latti_newcell = false;
for(int i = 0; i < 2; i++){
if (latti_cell[i] != entry2[i]) {
latti_newcell=true;
}
}
if (!latti_newcell) {
latti_lub = lbf_lub(latti_lub, entry2[2]);
} else {
break;
}
}
latti_cell[2] = latti_lub;
rel_11_org_lat_varEntry->insert(latti_cell);
} else {
++it;
}
latti_first = false;
}
}
std::swap(rel_8_varEntry, rel_11_org_lat_varEntry);
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_9_delta_varEntry->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_10_new_varEntry->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_11_org_lat_varEntry->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_12_new_lat_varEntry->purge();
// LatNorm
if (!rel_13_varExit->empty()) {
Tuple<RamDomain, 3> latti_cell;
bool latti_first = true;
RamDomain latti_lub;
for(auto it = rel_13_varExit->begin(); it != rel_13_varExit->end();) {
const auto& entry = *it;
bool latti_newcell = latti_first;
for(int i = 0; i < 2; i++){
if (latti_cell[i] != entry[i]) {
latti_cell[i] = entry[i]; latti_newcell=true;
}
}
if (latti_newcell) {
latti_lub = RamDomain(2147418112);
for (; it != rel_13_varExit->end(); ++it) {
const auto& entry2 = *it;
latti_newcell = false;
for(int i = 0; i < 2; i++){
if (latti_cell[i] != entry2[i]) {
latti_newcell=true;
}
}
if (!latti_newcell) {
latti_lub = lbf_lub(latti_lub, entry2[2]);
} else {
break;
}
}
latti_cell[2] = latti_lub;
rel_16_org_lat_varExit->insert(latti_cell);
} else {
++it;
}
latti_first = false;
}
}
std::swap(rel_13_varExit, rel_16_org_lat_varExit);
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_14_delta_varExit->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_15_new_varExit->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_16_org_lat_varExit->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_17_new_lat_varExit->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","l\tk\tv"},{"filename","const_prop/out/prog-50L-3000/compiled-8/varEntry.csv"},{"name","varEntry"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({0, 1, 0}), EnumTypeMask({0, 0, 1}), symTable, ioDirectives, 0)->writeAll(*rel_8_varEntry);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","l\tk\tv"},{"filename","const_prop/out/prog-50L-3000/compiled-8/varExit.csv"},{"name","varExit"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({0, 1, 0}), EnumTypeMask({0, 0, 1}), symTable, ioDirectives, 0)->writeAll(*rel_13_varExit);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_5_setConstStm->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_1_addStm->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_3_minusStm->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_4_multStm->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_2_divStm->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_6_assignVar->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_7_flow->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_8_varEntry->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_13_varExit->purge();
}();
/* END STRATUM 7 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_addStm:\n";
rel_1_addStm->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_divStm:\n";
rel_2_divStm->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_minusStm:\n";
rel_3_minusStm->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_multStm:\n";
rel_4_multStm->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_setConstStm:\n";
rel_5_setConstStm->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_assignVar:\n";
rel_6_assignVar->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_flow:\n";
rel_7_flow->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_varEntry:\n";
rel_8_varEntry->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_delta_varEntry:\n";
rel_9_delta_varEntry->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_new_varEntry:\n";
rel_10_new_varEntry->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_org_lat_varEntry:\n";
rel_11_org_lat_varEntry->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_new_lat_varEntry:\n";
rel_12_new_lat_varEntry->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_13_varExit:\n";
rel_13_varExit->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_14_delta_varExit:\n";
rel_14_delta_varExit->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_15_new_varExit:\n";
rel_15_new_varExit->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_16_org_lat_varExit:\n";
rel_16_org_lat_varExit->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_17_new_lat_varExit:\n";
rel_17_new_lat_varExit->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_18_lat_temp_varExit:\n";
rel_18_lat_temp_varExit->printHintStatistics(std::cout,"  ");
std::cout << "\n";
}
SignalHandler::instance()->reset();
}
public:
void run(size_t stratumIndex = (size_t) -1) override { runFunction(".", ".", stratumIndex, false); }
public:
void runAll(std::string inputDirectory = ".", std::string outputDirectory = ".", size_t stratumIndex = (size_t) -1) override { runFunction(inputDirectory, outputDirectory, stratumIndex, true);
}
public:
void printAll(std::string outputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","l\tk\tv"},{"filename","const_prop/out/prog-50L-3000/compiled-8/varEntry.csv"},{"name","varEntry"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({0, 1, 0}), EnumTypeMask({0, 0, 1}), symTable, ioDirectives, 0)->writeAll(*rel_8_varEntry);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","l\tk\tv"},{"filename","const_prop/out/prog-50L-3000/compiled-8/varExit.csv"},{"name","varExit"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({0, 1, 0}), EnumTypeMask({0, 0, 1}), symTable, ioDirectives, 0)->writeAll(*rel_13_varExit);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/addStm.facts"},{"name","addStm"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 1, 1, 1}), EnumTypeMask({0, 0, 0, 0}), symTable, ioDirectives, 0)->readAll(*rel_1_addStm);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/divStm.facts"},{"name","divStm"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 1, 1, 1}), EnumTypeMask({0, 0, 0, 0}), symTable, ioDirectives, 0)->readAll(*rel_2_divStm);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/minusStm.facts"},{"name","minusStm"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 1, 1, 1}), EnumTypeMask({0, 0, 0, 0}), symTable, ioDirectives, 0)->readAll(*rel_3_minusStm);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/multStm.facts"},{"name","multStm"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 1, 1, 1}), EnumTypeMask({0, 0, 0, 0}), symTable, ioDirectives, 0)->readAll(*rel_4_multStm);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/setConstStm.facts"},{"name","setConstStm"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 1, 0}), EnumTypeMask({0, 0, 0}), symTable, ioDirectives, 0)->readAll(*rel_5_setConstStm);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/flow.facts"},{"name","flow"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 0}), EnumTypeMask({0, 0}), symTable, ioDirectives, 0)->readAll(*rel_7_flow);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","facts/prog-50L-3000/varEntry.facts"},{"name","varEntry"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 1, 0}), EnumTypeMask({0, 0, 1}), symTable, ioDirectives, 0)->readAll(*rel_8_varEntry);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_addStm");
IOSystem::getInstance().getWriter(SymbolMask({0, 1, 1, 1}),EnumTypeMask({0, 1, 1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_1_addStm);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_divStm");
IOSystem::getInstance().getWriter(SymbolMask({0, 1, 1, 1}),EnumTypeMask({0, 1, 1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_2_divStm);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_minusStm");
IOSystem::getInstance().getWriter(SymbolMask({0, 1, 1, 1}),EnumTypeMask({0, 1, 1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_3_minusStm);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_4_multStm");
IOSystem::getInstance().getWriter(SymbolMask({0, 1, 1, 1}),EnumTypeMask({0, 1, 1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_4_multStm);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_5_setConstStm");
IOSystem::getInstance().getWriter(SymbolMask({0, 1, 0}),EnumTypeMask({0, 1, 0}), symTable, ioDirectives, 0)->writeAll(*rel_5_setConstStm);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_7_flow");
IOSystem::getInstance().getWriter(SymbolMask({0, 0}),EnumTypeMask({0, 0}), symTable, ioDirectives, 0)->writeAll(*rel_7_flow);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_8_varEntry");
IOSystem::getInstance().getWriter(SymbolMask({0, 1, 0}),EnumTypeMask({0, 1, 0}), symTable, ioDirectives, 0)->writeAll(*rel_8_varEntry);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_8_varEntry");
IOSystem::getInstance().getWriter(SymbolMask({0, 1, 0}),EnumTypeMask({0, 1, 0}), symTable, ioDirectives, 0)->writeAll(*rel_8_varEntry);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_13_varExit");
IOSystem::getInstance().getWriter(SymbolMask({0, 1, 0}),EnumTypeMask({0, 1, 0}), symTable, ioDirectives, 0)->writeAll(*rel_13_varExit);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
const SymbolTable &getSymbolTable() const override {
return symTable;
}
};
SouffleProgram *newInstance_const_prop(){return new Sf_const_prop;}
SymbolTable *getST_const_prop(SouffleProgram *p){return &reinterpret_cast<Sf_const_prop*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_const_prop: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_const_prop();
};
public:
factory_Sf_const_prop() : ProgramFactory("const_prop"){}
};
static factory_Sf_const_prop __factory_Sf_const_prop_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(const_prop/const_prop.dl)",
R"(.)",
R"(.)",
false,
R"()",
8,
-1);
if (!opt.parse(argc,argv)) return 1;
#if defined(_OPENMP) 
omp_set_nested(true);

#endif
souffle::Sf_const_prop obj;
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
