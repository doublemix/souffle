
#include "souffle/CompiledSouffle.h"

extern "C" {
}

namespace souffle {
using namespace ram;
struct t_btree_1__0__1 {
using t_tuple = Tuple<RamDomain, 1>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0>>;
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
RamDomain data[1];
std::copy(ramDomain, ramDomain + 1, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0) {
RamDomain data[1] = {a0};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_1__0__1& other) {
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
range<t_ind_0::iterator> equalRange_1(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
context h;
return equalRange_1(t, h);
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
o << prefix << "arity 1 direct b-tree index [0]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_1__0 {
using t_tuple = Tuple<RamDomain, 1>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0>>;
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
RamDomain data[1];
std::copy(ramDomain, ramDomain + 1, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0) {
RamDomain data[1] = {a0};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_1__0& other) {
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
o << prefix << "arity 1 direct b-tree index [0]: (hits/misses/total)\n";
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
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 2 direct b-tree index [0,1]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};

class Sf_xmitch : public SouffleProgram {
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
	R"_(small)_",
	R"_(big)_",
};// -- Table: b
std::unique_ptr<t_btree_1__0__1> rel_1_b = std::make_unique<t_btree_1__0__1>();
souffle::RelationWrapper<0,t_btree_1__0__1,Tuple<RamDomain,1>,1> wrapper_rel_1_b;
// -- Table: @delta_b
std::unique_ptr<t_btree_1__0> rel_2_delta_b = std::make_unique<t_btree_1__0>();
// -- Table: @new_b
std::unique_ptr<t_btree_1__0> rel_3_new_b = std::make_unique<t_btree_1__0>();
// -- Table: a
std::unique_ptr<t_btree_2__0_1> rel_4_a = std::make_unique<t_btree_2__0_1>();
souffle::RelationWrapper<1,t_btree_2__0_1,Tuple<RamDomain,2>,2> wrapper_rel_4_a;
public:
Sf_xmitch() : 
wrapper_rel_1_b(*rel_1_b,symTable,"b",std::array<const char *,1>{{"i:number"}},std::array<const char *,1>{{"n"}}),

wrapper_rel_4_a(*rel_4_a,symTable,"a",std::array<const char *,2>{{"i:number","s:symbol"}},std::array<const char *,2>{{"n","type"}}){
addRelation("b",&wrapper_rel_1_b,false,false);
addRelation("a",&wrapper_rel_4_a,false,true);
}
~Sf_xmitch() {
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
SignalHandler::instance()->setMsg(R"_(b(0).
in file /home/doublemix/workspace/souffle-qxg2/dataflowTest/mitch/test.dl [4:1-4:6])_");
rel_1_b->insert(RamDomain(0));
rel_2_delta_b->insertAll(*rel_1_b);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(b(Intrsc(n + 1)) :- 
   b(n),
   n < 10.
in file /home/doublemix/workspace/souffle-qxg2/dataflowTest/mitch/test.dl [5:1-5:26])_");
if (!rel_2_delta_b->empty()) [&](){
auto part = rel_2_delta_b->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_delta_b_op_ctxt,rel_2_delta_b->createContext());
CREATE_OP_CONTEXT(rel_3_new_b_op_ctxt,rel_3_new_b->createContext());
CREATE_OP_CONTEXT(rel_1_b_op_ctxt,rel_1_b->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
if( ((env0[0]) < (RamDomain(10)))) {
if( !(rel_1_b->contains(Tuple<RamDomain,1>({{(env0[0]) + (RamDomain(1))}}),READ_OP_CONTEXT(rel_1_b_op_ctxt)))) {
Tuple<RamDomain,1> tuple({{static_cast<RamDomain>((env0[0]) + (RamDomain(1)))}});
rel_3_new_b->insert(tuple,READ_OP_CONTEXT(rel_3_new_b_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();if(rel_3_new_b->empty()) break;
rel_1_b->insertAll(*rel_3_new_b);
std::swap(rel_2_delta_b, rel_3_new_b);
rel_3_new_b->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_2_delta_b->purge();
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_3_new_b->purge();
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
SignalHandler::instance()->setMsg(R"_(a(n,n > 5 ? "big" : "small") :- 
   b(n).
in file /home/doublemix/workspace/souffle-qxg2/dataflowTest/mitch/test.dl [6:1-6:39])_");
if (!rel_1_b->empty()) [&](){
auto part = rel_1_b->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_4_a_op_ctxt,rel_4_a->createContext());
CREATE_OP_CONTEXT(rel_1_b_op_ctxt,rel_1_b->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>((((env0[0]) > (RamDomain(5)))) ? (RamDomain(0)) : (RamDomain(1)))}});
rel_4_a->insert(tuple,READ_OP_CONTEXT(rel_4_a_op_ctxt));
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","n\ttype"},{"filename","./a.csv"},{"name","a"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({0, 1}), EnumTypeMask({0, 0}), symTable, ioDirectives, 0)->writeAll(*rel_4_a);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_1_b->purge();
}();
/* END STRATUM 1 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_b:\n";
rel_1_b->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_delta_b:\n";
rel_2_delta_b->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_new_b:\n";
rel_3_new_b->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_a:\n";
rel_4_a->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","n\ttype"},{"filename","./a.csv"},{"name","a"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({0, 1}), EnumTypeMask({0, 0}), symTable, ioDirectives, 0)->writeAll(*rel_4_a);
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
ioDirectives.setRelationName("rel_4_a");
IOSystem::getInstance().getWriter(SymbolMask({0, 1}),EnumTypeMask({0, 1}), symTable, ioDirectives, 0)->writeAll(*rel_4_a);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
const SymbolTable &getSymbolTable() const override {
return symTable;
}
};
SouffleProgram *newInstance_xmitch(){return new Sf_xmitch;}
SymbolTable *getST_xmitch(SouffleProgram *p){return &reinterpret_cast<Sf_xmitch*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_xmitch: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_xmitch();
};
public:
factory_Sf_xmitch() : ProgramFactory("xmitch"){}
};
static factory_Sf_xmitch __factory_Sf_xmitch_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(test.dl)",
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
souffle::Sf_xmitch obj;
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
