
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

RamDomain luf_next(RamDomain);
RamDomain lbf_glb(RamDomain, RamDomain);
RamDomain lbf_lub(RamDomain, RamDomain);

RamDomain luf_next(RamDomain arg0) {
  RamDomain args[1] = { arg0 };
if ((((args)[0]) == (RamDomain(2147418114)))) {
return (RamDomain(2147418113));
}
if ((((args)[0]) == (RamDomain(2147418113)))) {
return (RamDomain(2147418112));
}
if ((((args)[0]) == (RamDomain(2147418112)))) {
return (RamDomain(2147418111));
}
return (RamDomain(2147418114));
}
RamDomain lbf_glb(RamDomain arg0, RamDomain arg1) {
  RamDomain args[2] = { arg0, arg1 };
if ((((args)[0]) == (RamDomain(2147418114)))) {
return (RamDomain(2147418114));
}
if ((((args)[1]) == (RamDomain(2147418114)))) {
return (RamDomain(2147418114));
}
return (((((args)[0]) == ((args)[1]))) ? ((args)[0]) : (RamDomain(2147418111)));
}
RamDomain lbf_lub(RamDomain arg0, RamDomain arg1) {
  RamDomain args[2] = { arg0, arg1 };
if ((((args)[0]) == (RamDomain(2147418111)))) {
return (RamDomain(2147418111));
}
if ((((args)[1]) == (RamDomain(2147418111)))) {
return (RamDomain(2147418111));
}
return (((((args)[0]) == ((args)[1]))) ? ((args)[0]) : (RamDomain(2147418114)));
}
class Sf_test3 : public SouffleProgram {
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
	std::make_pair(R"_(Bot)_",2147418114),
	std::make_pair(R"_(Pos)_",2147418113),
	std::make_pair(R"_(Neg)_",2147418112),
	std::make_pair(R"_(Top)_",2147418111),
};// -- Table: b
std::unique_ptr<t_btree_2__0_1> rel_1_b = std::make_unique<t_btree_2__0_1>();
souffle::RelationWrapper<0,t_btree_2__0_1,Tuple<RamDomain,2>,2> wrapper_rel_1_b;
// -- Table: @lat_temp_b
std::unique_ptr<t_btree_2__0_1> rel_2_lat_temp_b = std::make_unique<t_btree_2__0_1>();
// -- Table: c
std::unique_ptr<t_btree_2__0_1> rel_3_c = std::make_unique<t_btree_2__0_1>();
souffle::RelationWrapper<1,t_btree_2__0_1,Tuple<RamDomain,2>,2> wrapper_rel_3_c;
// -- Table: @lat_temp_c
std::unique_ptr<t_btree_2__0_1> rel_4_lat_temp_c = std::make_unique<t_btree_2__0_1>();
// -- Table: a
std::unique_ptr<t_btree_2__0_1__3> rel_5_a = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<2,t_btree_2__0_1__3,Tuple<RamDomain,2>,2> wrapper_rel_5_a;
// -- Table: @delta_a
std::unique_ptr<t_btree_2__0_1> rel_6_delta_a = std::make_unique<t_btree_2__0_1>();
// -- Table: @new_a
std::unique_ptr<t_btree_2__0_1> rel_7_new_a = std::make_unique<t_btree_2__0_1>();
// -- Table: @org_lat_a
std::unique_ptr<t_btree_2__0_1> rel_8_org_lat_a = std::make_unique<t_btree_2__0_1>();
// -- Table: @new_lat_a
std::unique_ptr<t_btree_2__0_1> rel_9_new_lat_a = std::make_unique<t_btree_2__0_1>();
// -- Table: @lat_temp_a
std::unique_ptr<t_btree_2__0_1> rel_10_lat_temp_a = std::make_unique<t_btree_2__0_1>();
public:
Sf_test3() : 
wrapper_rel_1_b(*rel_1_b,symTable,"b",std::array<const char *,2>{{"i:number","e:Lattice{Top:s:symbol,Neg:s:symbol,Pos:s:symbol,Bot:s:symbol}"}},std::array<const char *,2>{{"n","l"}}),

wrapper_rel_3_c(*rel_3_c,symTable,"c",std::array<const char *,2>{{"i:number","e:Lattice{Top:s:symbol,Neg:s:symbol,Pos:s:symbol,Bot:s:symbol}"}},std::array<const char *,2>{{"n","l"}}),

wrapper_rel_5_a(*rel_5_a,symTable,"a",std::array<const char *,2>{{"i:number","e:Lattice{Top:s:symbol,Neg:s:symbol,Pos:s:symbol,Bot:s:symbol}"}},std::array<const char *,2>{{"x","l"}}){
addRelation("b",&wrapper_rel_1_b,false,false);
addRelation("c",&wrapper_rel_3_c,false,false);
addRelation("a",&wrapper_rel_5_a,false,true);
}
~Sf_test3() {
}
private:
void runFunction(std::string inputDirectory = ".", std::string outputDirectory = ".", size_t stratumIndex = (size_t) -1, bool performIO = false) {
SignalHandler::instance()->set();
std::atomic<size_t> iter(0);

#if defined(__EMBEDDED_SOUFFLE__) && defined(_OPENMP)
omp_set_num_threads(1);
#endif

// -- query evaluation --
/* BEGIN STRATUM 0 */
[&]() {
SignalHandler::instance()->setMsg(R"_(b(1,"Pos").
in file /home/doublemix/workspace/souffle-qxg2/mitch/test3.dl [29:1-29:13])_");
rel_1_b->insert(RamDomain(1),RamDomain(2147418113));
// LatNorm
if (!rel_1_b->empty()) {
Tuple<RamDomain, 2> latti_cell;
bool latti_first = true;
RamDomain latti_lub;
for(auto it = rel_1_b->begin(); it != rel_1_b->end();) {
const auto& entry = *it;
bool latti_newcell = latti_first;
for(int i = 0; i < 1; i++){
if (latti_cell[i] != entry[i]) {
latti_cell[i] = entry[i]; latti_newcell=true;
}
}
if (latti_newcell) {
latti_lub = RamDomain(2147418114);
for (; it != rel_1_b->end(); ++it) {
const auto& entry2 = *it;
latti_newcell = false;
for(int i = 0; i < 1; i++){
if (latti_cell[i] != entry2[i]) {
latti_newcell=true;
}
}
if (!latti_newcell) {
latti_lub = lbf_lub(latti_lub, entry2[1]);
} else {
break;
}
}
latti_cell[1] = latti_lub;
rel_2_lat_temp_b->insert(latti_cell);
} else {
++it;
}
latti_first = false;
}
}
rel_1_b->purge();
rel_1_b->insertAll(*rel_2_lat_temp_b);
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_2_lat_temp_b->purge();
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
SignalHandler::instance()->setMsg(R"_(c(1,"Pos").
in file /home/doublemix/workspace/souffle-qxg2/mitch/test3.dl [30:1-30:13])_");
rel_3_c->insert(RamDomain(1),RamDomain(2147418113));
// LatNorm
if (!rel_3_c->empty()) {
Tuple<RamDomain, 2> latti_cell;
bool latti_first = true;
RamDomain latti_lub;
for(auto it = rel_3_c->begin(); it != rel_3_c->end();) {
const auto& entry = *it;
bool latti_newcell = latti_first;
for(int i = 0; i < 1; i++){
if (latti_cell[i] != entry[i]) {
latti_cell[i] = entry[i]; latti_newcell=true;
}
}
if (latti_newcell) {
latti_lub = RamDomain(2147418114);
for (; it != rel_3_c->end(); ++it) {
const auto& entry2 = *it;
latti_newcell = false;
for(int i = 0; i < 1; i++){
if (latti_cell[i] != entry2[i]) {
latti_newcell=true;
}
}
if (!latti_newcell) {
latti_lub = lbf_lub(latti_lub, entry2[1]);
} else {
break;
}
}
latti_cell[1] = latti_lub;
rel_4_lat_temp_c->insert(latti_cell);
} else {
++it;
}
latti_first = false;
}
}
rel_3_c->purge();
rel_3_c->insertAll(*rel_4_lat_temp_c);
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_4_lat_temp_c->purge();
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
SignalHandler::instance()->setMsg(R"_(a(n,l) :- 
   b(n,l),
   c(n,l).
in file /home/doublemix/workspace/souffle-qxg2/mitch/test3.dl [32:1-32:29])_");
if (!rel_1_b->empty()&&!rel_3_c->empty()) [&](){
auto part = rel_1_b->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_5_a_op_ctxt,rel_5_a->createContext());
CREATE_OP_CONTEXT(rel_1_b_op_ctxt,rel_1_b->createContext());
CREATE_OP_CONTEXT(rel_3_c_op_ctxt,rel_3_c->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_c) {
if( ((env0[0]) == (env1[0]))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(lbf_glb(env0[1],env1[1]))}});
rel_5_a->insert(tuple,READ_OP_CONTEXT(rel_5_a_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();// LatNorm
if (!rel_5_a->empty()) {
Tuple<RamDomain, 2> latti_cell;
bool latti_first = true;
RamDomain latti_lub;
for(auto it = rel_5_a->begin(); it != rel_5_a->end();) {
const auto& entry = *it;
bool latti_newcell = latti_first;
for(int i = 0; i < 1; i++){
if (latti_cell[i] != entry[i]) {
latti_cell[i] = entry[i]; latti_newcell=true;
}
}
if (latti_newcell) {
latti_lub = RamDomain(2147418114);
for (; it != rel_5_a->end(); ++it) {
const auto& entry2 = *it;
latti_newcell = false;
for(int i = 0; i < 1; i++){
if (latti_cell[i] != entry2[i]) {
latti_newcell=true;
}
}
if (!latti_newcell) {
latti_lub = lbf_lub(latti_lub, entry2[1]);
} else {
break;
}
}
latti_cell[1] = latti_lub;
rel_10_lat_temp_a->insert(latti_cell);
} else {
++it;
}
latti_first = false;
}
}
rel_5_a->purge();
rel_5_a->insertAll(*rel_10_lat_temp_a);
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_10_lat_temp_a->purge();
rel_6_delta_a->insertAll(*rel_5_a);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(a(Intrsc(n + 1),&next(l)) :- 
   a(n,l),
   n < 10.
in file /home/doublemix/workspace/souffle-qxg2/mitch/test3.dl [33:1-33:39])_");
if (!rel_6_delta_a->empty()) [&](){
auto part = rel_6_delta_a->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_6_delta_a_op_ctxt,rel_6_delta_a->createContext());
CREATE_OP_CONTEXT(rel_7_new_a_op_ctxt,rel_7_new_a->createContext());
CREATE_OP_CONTEXT(rel_5_a_op_ctxt,rel_5_a->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
if( ((env0[0]) < (RamDomain(10)))) {
if( !(rel_5_a->contains(Tuple<RamDomain,2>({{(env0[0]) + (RamDomain(1)),luf_next(env0[1])}}),READ_OP_CONTEXT(rel_5_a_op_ctxt)))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>((env0[0]) + (RamDomain(1))),static_cast<RamDomain>(luf_next(env0[1]))}});
rel_7_new_a->insert(tuple,READ_OP_CONTEXT(rel_7_new_a_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();SignalHandler::instance()->setMsg(R"_(a(Intrsc(n + 1),&next(&next(l))) :- 
   a(n,l),
   n < 10.
in file /home/doublemix/workspace/souffle-qxg2/mitch/test3.dl [34:1-34:46])_");
if (!rel_6_delta_a->empty()) [&](){
auto part = rel_6_delta_a->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_6_delta_a_op_ctxt,rel_6_delta_a->createContext());
CREATE_OP_CONTEXT(rel_7_new_a_op_ctxt,rel_7_new_a->createContext());
CREATE_OP_CONTEXT(rel_5_a_op_ctxt,rel_5_a->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
if( ((env0[0]) < (RamDomain(10)))) {
if( !(rel_5_a->contains(Tuple<RamDomain,2>({{(env0[0]) + (RamDomain(1)),luf_next(luf_next(env0[1]))}}),READ_OP_CONTEXT(rel_5_a_op_ctxt)))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>((env0[0]) + (RamDomain(1))),static_cast<RamDomain>(luf_next(luf_next(env0[1])))}});
rel_7_new_a->insert(tuple,READ_OP_CONTEXT(rel_7_new_a_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();// LatClean
if (!rel_7_new_a->empty()) {
Tuple<RamDomain, 2> latti_cell;
bool latti_first = true;
RamDomain latti_lub;
for(auto it = rel_7_new_a->begin(); it != rel_7_new_a->end();) {
const auto& entry = *it;
bool latti_newcell = latti_first;
for(int i = 0; i < 1; i++){
if (latti_cell[i] != entry[i]) {
latti_cell[i] = entry[i]; latti_newcell=true;
}
}
if (latti_newcell) {
latti_lub = RamDomain(2147418114);
auto latti_range = rel_5_a->lattice_range(latti_cell);
for(auto idx = latti_range.begin(); idx != latti_range.end(); ++idx) {
latti_lub = lbf_lub(latti_lub, (*idx)[1]);
}
for (; it != rel_7_new_a->end(); ++it) {
const auto& entry2 = *it;
latti_newcell = false;
for(int i = 0; i < 1; i++){
if (latti_cell[i] != entry2[i]) {
latti_newcell=true;
}
}
if (!latti_newcell) {
latti_lub = lbf_lub(latti_lub, entry2[1]);
} else {
break;
}
}
latti_cell[1] = latti_lub;
if (!rel_5_a->contains(latti_cell)) {
rel_9_new_lat_a->insert(latti_cell);
}
} else {
++it;
}
latti_first = false;
}
}
std::swap(rel_7_new_a, rel_9_new_lat_a);
rel_9_new_lat_a->purge();
if(rel_7_new_a->empty()) break;
rel_5_a->insertAll(*rel_7_new_a);
std::swap(rel_6_delta_a, rel_7_new_a);
rel_7_new_a->purge();
iter++;
}
iter = 0;
// LatNorm
if (!rel_5_a->empty()) {
Tuple<RamDomain, 2> latti_cell;
bool latti_first = true;
RamDomain latti_lub;
for(auto it = rel_5_a->begin(); it != rel_5_a->end();) {
const auto& entry = *it;
bool latti_newcell = latti_first;
for(int i = 0; i < 1; i++){
if (latti_cell[i] != entry[i]) {
latti_cell[i] = entry[i]; latti_newcell=true;
}
}
if (latti_newcell) {
latti_lub = RamDomain(2147418114);
for (; it != rel_5_a->end(); ++it) {
const auto& entry2 = *it;
latti_newcell = false;
for(int i = 0; i < 1; i++){
if (latti_cell[i] != entry2[i]) {
latti_newcell=true;
}
}
if (!latti_newcell) {
latti_lub = lbf_lub(latti_lub, entry2[1]);
} else {
break;
}
}
latti_cell[1] = latti_lub;
rel_8_org_lat_a->insert(latti_cell);
} else {
++it;
}
latti_first = false;
}
}
rel_5_a->purge();
rel_5_a->insertAll(*rel_8_org_lat_a);
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_6_delta_a->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_7_new_a->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_8_org_lat_a->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_9_new_lat_a->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","x\tl"},{"filename","./out/a.csv"},{"name","a"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({0, 0}), EnumTypeMask({0, 1}), symTable, ioDirectives, 0)->writeAll(*rel_5_a);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_5_a->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_1_b->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_3_c->purge();
}();
/* END STRATUM 2 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_b:\n";
rel_1_b->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_lat_temp_b:\n";
rel_2_lat_temp_b->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_c:\n";
rel_3_c->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_lat_temp_c:\n";
rel_4_lat_temp_c->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_a:\n";
rel_5_a->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_delta_a:\n";
rel_6_delta_a->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_new_a:\n";
rel_7_new_a->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_org_lat_a:\n";
rel_8_org_lat_a->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_new_lat_a:\n";
rel_9_new_lat_a->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_lat_temp_a:\n";
rel_10_lat_temp_a->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","x\tl"},{"filename","./out/a.csv"},{"name","a"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({0, 0}), EnumTypeMask({0, 1}), symTable, ioDirectives, 0)->writeAll(*rel_5_a);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_5_a");
IOSystem::getInstance().getWriter(SymbolMask({0, 0}),EnumTypeMask({0, 0}), symTable, ioDirectives, 0)->writeAll(*rel_5_a);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
const SymbolTable &getSymbolTable() const override {
return symTable;
}
};
SouffleProgram *newInstance_test3(){return new Sf_test3;}
SymbolTable *getST_test3(SouffleProgram *p){return &reinterpret_cast<Sf_test3*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_test3: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_test3();
};
public:
factory_Sf_test3() : ProgramFactory("test3"){}
};
static factory_Sf_test3 __factory_Sf_test3_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(test3.dl)",
R"(.)",
R"(.)",
false,
R"()",
1,
-1);
if (!opt.parse(argc,argv)) return 1;
#if defined(_OPENMP) 
omp_set_nested(true);

#endif
souffle::Sf_test3 obj;
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
