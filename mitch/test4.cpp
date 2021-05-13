
#include "souffle/CompiledSouffle.h"

extern "C" {
}

namespace souffle {
using namespace ram;
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


class Sf_test4 : public SouffleProgram {
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
	std::make_pair(R"_(d)_",1),
	std::make_pair(R"_(s)_",0),
};// -- Table: a
std::unique_ptr<t_btree_2__0_1__3> rel_1_a = std::make_unique<t_btree_2__0_1__3>();
souffle::RelationWrapper<0,t_btree_2__0_1__3,Tuple<RamDomain,2>,2> wrapper_rel_1_a;
// -- Table: @delta_a
std::unique_ptr<t_btree_2__0_1> rel_2_delta_a = std::make_unique<t_btree_2__0_1>();
// -- Table: @new_a
std::unique_ptr<t_btree_2__0_1> rel_3_new_a = std::make_unique<t_btree_2__0_1>();
// -- Table: b
std::unique_ptr<t_btree_2__0_1> rel_4_b = std::make_unique<t_btree_2__0_1>();
souffle::RelationWrapper<1,t_btree_2__0_1,Tuple<RamDomain,2>,2> wrapper_rel_4_b;
public:
Sf_test4() : 
wrapper_rel_1_a(*rel_1_a,symTable,"a",std::array<const char *,2>{{"s:symbol","i:number"}},std::array<const char *,2>{{"s","n"}}),

wrapper_rel_4_b(*rel_4_b,symTable,"b",std::array<const char *,2>{{"s:symbol","i:number"}},std::array<const char *,2>{{"s","n"}}){
addRelation("a",&wrapper_rel_1_a,false,false);
addRelation("b",&wrapper_rel_4_b,false,true);
}
~Sf_test4() {
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
SignalHandler::instance()->setMsg(R"_(a("s",1).
in file /home/doublemix/workspace/souffle-qxg2/mitch/test4.dl [4:1-4:11])_");
rel_1_a->insert(RamDomain(0),RamDomain(1));
SignalHandler::instance()->setMsg(R"_(a("d",50).
in file /home/doublemix/workspace/souffle-qxg2/mitch/test4.dl [5:1-5:12])_");
rel_1_a->insert(RamDomain(1),RamDomain(50));
rel_2_delta_a->insertAll(*rel_1_a);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(a(s,Intrsc(n + 1)) :- 
   a(s,n),
   n < 100.
in file /home/doublemix/workspace/souffle-qxg2/mitch/test4.dl [6:1-6:33])_");
if (!rel_2_delta_a->empty()) [&](){
auto part = rel_2_delta_a->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_delta_a_op_ctxt,rel_2_delta_a->createContext());
CREATE_OP_CONTEXT(rel_3_new_a_op_ctxt,rel_3_new_a->createContext());
CREATE_OP_CONTEXT(rel_1_a_op_ctxt,rel_1_a->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
if( ((env0[1]) < (RamDomain(100)))) {
if( !(rel_1_a->contains(Tuple<RamDomain,2>({{env0[0],(env0[1]) + (RamDomain(1))}}),READ_OP_CONTEXT(rel_1_a_op_ctxt)))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>((env0[1]) + (RamDomain(1)))}});
rel_3_new_a->insert(tuple,READ_OP_CONTEXT(rel_3_new_a_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();if(rel_3_new_a->empty()) break;
rel_1_a->insertAll(*rel_3_new_a);
std::swap(rel_2_delta_a, rel_3_new_a);
rel_3_new_a->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_2_delta_a->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_3_new_a->purge();
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
SignalHandler::instance()->setMsg(R"_(b(s,Intrsc(n * 2)) :- 
   a(s,n).
in file /home/doublemix/workspace/souffle-qxg2/mitch/test4.dl [8:1-8:24])_");
if (!rel_1_a->empty()) [&](){
auto part = rel_1_a->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_a_op_ctxt,rel_1_a->createContext());
CREATE_OP_CONTEXT(rel_4_b_op_ctxt,rel_4_b->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>((env0[1]) * (RamDomain(2)))}});
rel_4_b->insert(tuple,READ_OP_CONTEXT(rel_4_b_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","s\tn"},{"filename","./out/test4/compiled/b.csv"},{"name","b"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({1, 0}), EnumTypeMask({0, 0}), symTable, ioDirectives, 0)->writeAll(*rel_4_b);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_1_a->purge();
}();
/* END STRATUM 1 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_a:\n";
rel_1_a->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_delta_a:\n";
rel_2_delta_a->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_new_a:\n";
rel_3_new_a->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_b:\n";
rel_4_b->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","s\tn"},{"filename","./out/test4/compiled/b.csv"},{"name","b"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({1, 0}), EnumTypeMask({0, 0}), symTable, ioDirectives, 0)->writeAll(*rel_4_b);
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
ioDirectives.setRelationName("rel_4_b");
IOSystem::getInstance().getWriter(SymbolMask({1, 0}),EnumTypeMask({1, 0}), symTable, ioDirectives, 0)->writeAll(*rel_4_b);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
const SymbolTable &getSymbolTable() const override {
return symTable;
}
};
SouffleProgram *newInstance_test4(){return new Sf_test4;}
SymbolTable *getST_test4(SouffleProgram *p){return &reinterpret_cast<Sf_test4*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_test4: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_test4();
};
public:
factory_Sf_test4() : ProgramFactory("test4"){}
};
static factory_Sf_test4 __factory_Sf_test4_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(test4.dl)",
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
souffle::Sf_test4 obj;
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
