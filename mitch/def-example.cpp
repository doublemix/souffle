
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

RamDomain luf_lat_negate(RamDomain);
RamDomain lbf_glb(RamDomain, RamDomain);
RamDomain lbf_lub(RamDomain, RamDomain);

RamDomain luf_lat_negate(RamDomain arg0) {
  RamDomain args[1] = { arg0 };
if ((((args)[0]) == (RamDomain(2147418112)))) {
return (RamDomain(2147418114));
}
if ((((args)[0]) == (RamDomain(2147418114)))) {
return (RamDomain(2147418112));
}
if ((((args)[0]) == (RamDomain(2147418113)))) {
return (RamDomain(2147418113));
}
if ((((args)[0]) == (RamDomain(2147418111)))) {
return (RamDomain(2147418111));
}
return (RamDomain(2147418115));
}
RamDomain lbf_glb(RamDomain arg0, RamDomain arg1) {
    RamDomain args[2] = {arg0, arg1};
    if ((((((args)[0]) == (RamDomain(2147418112)))) && ((((args)[1]) == (RamDomain(2147418114)))))) {
        return (RamDomain(2147418115));
    }
    if ((((args)[0]) == (RamDomain(2147418111)))) {
        return (RamDomain(2147418111));
    }
    if ((((args)[1]) == (RamDomain(2147418111)))) {
        return (RamDomain(2147418111));
    }
    return (((((args)[0]) == ((args)[1]))) ? ((args)[0]) : (RamDomain(2147418115)));
}
RamDomain lbf_lub(RamDomain arg0, RamDomain arg1) {
  RamDomain args[2] = { arg0, arg1 };
if ((((args)[0]) == (RamDomain(2147418115)))) {
return (RamDomain(2147418115));
}
if ((((args)[1]) == (RamDomain(2147418115)))) {
return (RamDomain(2147418115));
}
return (((((args)[0]) == ((args)[1]))) ? ((args)[0]) : (RamDomain(2147418111)));
}
class Sf_def_example : public SouffleProgram {
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
	R"_(Pos)_",
	R"_(Zero)_",
	R"_(Neg)_",
	R"_(Top)_",
};// -- Table: b
std::unique_ptr<t_btree_2__0_1> rel_1_b = std::make_unique<t_btree_2__0_1>();
souffle::RelationWrapper<0,t_btree_2__0_1,Tuple<RamDomain,2>,2> wrapper_rel_1_b;
// -- Table: c
std::unique_ptr<t_btree_2__0_1> rel_2_c = std::make_unique<t_btree_2__0_1>();
souffle::RelationWrapper<1,t_btree_2__0_1,Tuple<RamDomain,2>,2> wrapper_rel_2_c;
// -- Table: a
std::unique_ptr<t_btree_2__0_1> rel_3_a = std::make_unique<t_btree_2__0_1>();
souffle::RelationWrapper<2,t_btree_2__0_1,Tuple<RamDomain,2>,2> wrapper_rel_3_a;
// -- Table: @lat_temp_a
std::unique_ptr<t_btree_2__0_1> rel_4_lat_temp_a = std::make_unique<t_btree_2__0_1>();
public:
Sf_def_example() : 
wrapper_rel_1_b(*rel_1_b,symTable,"b",std::array<const char *,2>{{"i:number","e:Sign{Top:s:symbol,Neg:s:symbol,Zero:s:symbol,Pos:s:symbol,Bot:s:symbol}"}},std::array<const char *,2>{{"n","s"}}),

wrapper_rel_2_c(*rel_2_c,symTable,"c",std::array<const char *,2>{{"i:number","e:Sign{Top:s:symbol,Neg:s:symbol,Zero:s:symbol,Pos:s:symbol,Bot:s:symbol}"}},std::array<const char *,2>{{"n","s"}}),

wrapper_rel_3_a(*rel_3_a,symTable,"a",std::array<const char *,2>{{"i:number","e:Sign{Top:s:symbol,Neg:s:symbol,Zero:s:symbol,Pos:s:symbol,Bot:s:symbol}"}},std::array<const char *,2>{{"n","s"}}){
addRelation("b",&wrapper_rel_1_b,true,false);
addRelation("c",&wrapper_rel_2_c,true,false);
addRelation("a",&wrapper_rel_3_a,false,true);
}
~Sf_def_example() {
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
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./b.facts"},{"name","b"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 0}), symTable, ioDirectives, 0)->readAll(*rel_1_b);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./c.facts"},{"name","c"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 0}), symTable, ioDirectives, 0)->readAll(*rel_2_c);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
SignalHandler::instance()->setMsg(R"_(a(n,&lat_negate(s)) :- 
   b(n,s),
   c(n,s).
in file /home/doublemix/workspace/souffle-qxg2/mitch/def-example.dl [32:1-32:42])_");
if (!rel_1_b->empty()&&!rel_2_c->empty()) [&](){
auto part = rel_1_b->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_3_a_op_ctxt,rel_3_a->createContext());
CREATE_OP_CONTEXT(rel_1_b_op_ctxt,rel_1_b->createContext());
CREATE_OP_CONTEXT(rel_2_c_op_ctxt,rel_2_c->createContext());
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
for(const auto& env1 : *rel_2_c) {
if( ((env0[0]) == (env1[0]))) {
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(env0[0]),static_cast<RamDomain>(luf_lat_negate(lbf_glb(env0[1],env1[1])))}});
rel_3_a->insert(tuple,READ_OP_CONTEXT(rel_3_a_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();//TODO: visitLatNorm
std::swap(rel_3_a, rel_4_lat_temp_a);
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_4_lat_temp_a->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","n\ts"},{"filename","./a.csv"},{"name","a"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({0, 0}), EnumTypeMask({0, 1}), symTable, ioDirectives, 0)->writeAll(*rel_3_a);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_1_b->purge();
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_2_c->purge();
}();
/* END STRATUM 2 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_b:\n";
rel_1_b->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_c:\n";
rel_2_c->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_a:\n";
rel_3_a->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_lat_temp_a:\n";
rel_4_lat_temp_a->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","n\ts"},{"filename","./a.csv"},{"name","a"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({0, 0}), EnumTypeMask({0, 1}), symTable, ioDirectives, 0)->writeAll(*rel_3_a);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./b.facts"},{"name","b"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 0}), symTable, ioDirectives, 0)->readAll(*rel_1_b);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./c.facts"},{"name","c"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({0, 0}), symTable, ioDirectives, 0)->readAll(*rel_2_c);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_b");
IOSystem::getInstance().getWriter(SymbolMask({0, 0}),EnumTypeMask({0, 0}), symTable, ioDirectives, 0)->writeAll(*rel_1_b);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_c");
IOSystem::getInstance().getWriter(SymbolMask({0, 0}),EnumTypeMask({0, 0}), symTable, ioDirectives, 0)->writeAll(*rel_2_c);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_a");
IOSystem::getInstance().getWriter(SymbolMask({0, 0}),EnumTypeMask({0, 0}), symTable, ioDirectives, 0)->writeAll(*rel_3_a);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
const SymbolTable &getSymbolTable() const override {
return symTable;
}
};
SouffleProgram *newInstance_def_example(){return new Sf_def_example;}
SymbolTable *getST_def_example(SouffleProgram *p){return &reinterpret_cast<Sf_def_example*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_def_example: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_def_example();
};
public:
factory_Sf_def_example() : ProgramFactory("def_example"){}
};
static factory_Sf_def_example __factory_Sf_def_example_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(./mitch/def-example.dl)",
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
souffle::Sf_def_example obj;
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
