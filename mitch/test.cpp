
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

RamDomain lbf_glb(RamDomain, RamDomain);
RamDomain lbf_lub(RamDomain, RamDomain);

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
class Sf_test : public SouffleProgram {
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
};// -- Table: a
std::unique_ptr<t_btree_2__0_1> rel_1_a = std::make_unique<t_btree_2__0_1>();
souffle::RelationWrapper<0,t_btree_2__0_1,Tuple<RamDomain,2>,2> wrapper_rel_1_a;
// -- Table: @lat_temp_a
std::unique_ptr<t_btree_2__0_1> rel_2_lat_temp_a = std::make_unique<t_btree_2__0_1>();
public:
Sf_test() : 
wrapper_rel_1_a(*rel_1_a,symTable,"a",std::array<const char *,2>{{"i:number","e:Lattice{Top:s:symbol,Neg:s:symbol,Pos:s:symbol,Bot:s:symbol}"}},std::array<const char *,2>{{"x","l"}}){
addRelation("a",&wrapper_rel_1_a,false,true);
}
~Sf_test() {
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
SignalHandler::instance()->setMsg(R"_(a(1,"Bot").
in file /home/doublemix/workspace/souffle-qxg2/mitch/test.dl [21:1-21:13])_");
rel_1_a->insert(RamDomain(1),RamDomain(2147418114));
SignalHandler::instance()->setMsg(R"_(a(1,"Top").
in file /home/doublemix/workspace/souffle-qxg2/mitch/test.dl [22:1-22:13])_");
rel_1_a->insert(RamDomain(1),RamDomain(2147418111));
// LatNorm
if (!rel_1_a->empty()) {
Tuple<RamDomain, 2> latti_cell;
bool latti_first = true;
RamDomain latti_lub;
for(auto it = rel_1_a->begin(); it != rel_1_a->end();) {
const auto& entry = *it;
bool latti_newcell = latti_first;
for(int i = 0; i < 1; i++){
if (latti_cell[i] != entry[i]) {
latti_cell[i] = entry[i]; latti_newcell=true;
}
}
if (latti_newcell) {
latti_lub = RamDomain(2147418114);
for (; it != rel_1_a->end(); ++it) {
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
rel_2_lat_temp_a->insert(latti_cell);
} else {
++it;
}
latti_first = false;
}
}
rel_1_a->purge();
rel_1_a->insertAll(*rel_2_lat_temp_a);
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_2_lat_temp_a->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","x\tl"},{"filename","./out/a.csv"},{"name","a"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({0, 0}), EnumTypeMask({0, 1}), symTable, ioDirectives, 0)->writeAll(*rel_1_a);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 0 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_a:\n";
rel_1_a->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_lat_temp_a:\n";
rel_2_lat_temp_a->printHintStatistics(std::cout,"  ");
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
IOSystem::getInstance().getWriter(SymbolMask({0, 0}), EnumTypeMask({0, 1}), symTable, ioDirectives, 0)->writeAll(*rel_1_a);
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
ioDirectives.setRelationName("rel_1_a");
IOSystem::getInstance().getWriter(SymbolMask({0, 0}),EnumTypeMask({0, 0}), symTable, ioDirectives, 0)->writeAll(*rel_1_a);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
const SymbolTable &getSymbolTable() const override {
return symTable;
}
};
SouffleProgram *newInstance_test(){return new Sf_test;}
SymbolTable *getST_test(SouffleProgram *p){return &reinterpret_cast<Sf_test*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_test: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_test();
};
public:
factory_Sf_test() : ProgramFactory("test"){}
};
static factory_Sf_test __factory_Sf_test_instance;
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
souffle::Sf_test obj;
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
