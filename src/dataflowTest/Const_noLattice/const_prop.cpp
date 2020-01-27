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
	context createContext() {
		return context();
	}
	bool insert(const t_tuple& t) {
		context h;
		return insert(t, h);
	}
	bool insert(const t_tuple& t, context& h) {
		if (ind_0.insert(t, h.hints_0)) {
			return true;
		} else
			return false;
	}
	bool insert(const RamDomain* ramDomain) {
		RamDomain data[2];
		std::copy(ramDomain, ramDomain + 2, data);
		const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
		context h;
		return insert(tuple, h);
	}
	bool insert(RamDomain a0, RamDomain a1) {
		RamDomain data[2] = { a0, a1 };
		return insert(data);
	}
	template<typename T>
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
		return range<iterator>(ind_0.begin(), ind_0.end());
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
		o << prefix
				<< "arity 2 direct b-tree index [0,1]: (hits/misses/total)\n";
		o << prefix << "Insert: " << stats_0.inserts.getHits() << "/"
				<< stats_0.inserts.getMisses() << "/"
				<< stats_0.inserts.getAccesses() << "\n";
		o << prefix << "Contains: " << stats_0.contains.getHits() << "/"
				<< stats_0.contains.getMisses() << "/"
				<< stats_0.contains.getAccesses() << "\n";
		o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/"
				<< stats_0.lower_bound.getMisses() << "/"
				<< stats_0.lower_bound.getAccesses() << "\n";
		o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/"
				<< stats_0.upper_bound.getMisses() << "/"
				<< stats_0.upper_bound.getAccesses() << "\n";
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
	context createContext() {
		return context();
	}
	bool insert(const t_tuple& t) {
		context h;
		return insert(t, h);
	}
	bool insert(const t_tuple& t, context& h) {
		if (ind_0.insert(t, h.hints_0)) {
			return true;
		} else
			return false;
	}
	bool insert(const RamDomain* ramDomain) {
		RamDomain data[2];
		std::copy(ramDomain, ramDomain + 2, data);
		const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
		context h;
		return insert(tuple, h);
	}
	bool insert(RamDomain a0, RamDomain a1) {
		RamDomain data[2] = { a0, a1 };
		return insert(data);
	}
	template<typename T>
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
		return range<iterator>(ind_0.begin(), ind_0.end());
	}
	range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
		auto pos = ind_0.find(t, h.hints_0);
		auto fin = ind_0.end();
		if (pos != fin) {
			fin = pos;
			++fin;
		}
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
		o << prefix
				<< "arity 2 direct b-tree index [0,1]: (hits/misses/total)\n";
		o << prefix << "Insert: " << stats_0.inserts.getHits() << "/"
				<< stats_0.inserts.getMisses() << "/"
				<< stats_0.inserts.getAccesses() << "\n";
		o << prefix << "Contains: " << stats_0.contains.getHits() << "/"
				<< stats_0.contains.getMisses() << "/"
				<< stats_0.contains.getAccesses() << "\n";
		o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/"
				<< stats_0.lower_bound.getMisses() << "/"
				<< stats_0.lower_bound.getAccesses() << "\n";
		o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/"
				<< stats_0.upper_bound.getMisses() << "/"
				<< stats_0.upper_bound.getAccesses() << "\n";
	}
};

class Sf_const_prop: public SouffleProgram {
private:
	static inline bool regex_wrapper(const std::string& pattern,
			const std::string& text) {
		bool result = false;
		try {
			result = std::regex_match(text, std::regex(pattern));
		} catch (...) {
			std::cerr << "warning: wrong pattern provided for match(\""
					<< pattern << "\",\"" << text << "\").\n";
		}
		return result;
	}
private:
	static inline std::string substr_wrapper(const std::string& str, size_t idx,
			size_t len) {
		std::string result;
		try {
			result = str.substr(idx, len);
		} catch (...) {
			std::cerr << "warning: wrong index position provided by substr(\"";
			std::cerr << str << "\"," << (int32_t) idx << "," << (int32_t) len
					<< ") functor.\n";
		}
		return result;
	}
private:
	static inline RamDomain wrapper_tonumber(const std::string& str) {
		RamDomain result = 0;
		try {
			result = stord(str);
		} catch (...) {
			std::cerr << "error: wrong string provided by to_number(\"";
			std::cerr << str << "\") functor.\n";
			raise (SIGFPE);
		}
		return result;
	}
public:
// -- initialize symbol table --
	SymbolTable symTable { R"_(Bot)_", R"_(Top)_", }; // -- Table: B
	std::unique_ptr<t_btree_2__0_1> rel_1_B =
			std::make_unique<t_btree_2__0_1>();
	souffle::RelationWrapper<0, t_btree_2__0_1, Tuple<RamDomain, 2>, 2> wrapper_rel_1_B;
// -- Table: C
	std::unique_ptr<t_btree_2__0_1> rel_2_C =
			std::make_unique<t_btree_2__0_1>();
	souffle::RelationWrapper<1, t_btree_2__0_1, Tuple<RamDomain, 2>, 2> wrapper_rel_2_C;
// -- Table: D
	std::unique_ptr<t_btree_2__0_1> rel_3_D =
			std::make_unique<t_btree_2__0_1>();
	souffle::RelationWrapper<2, t_btree_2__0_1, Tuple<RamDomain, 2>, 2> wrapper_rel_3_D;
// -- Table: A
	std::unique_ptr<t_btree_2__0_1__3> rel_4_A = std::make_unique<
			t_btree_2__0_1__3>();
	souffle::RelationWrapper<3, t_btree_2__0_1__3, Tuple<RamDomain, 2>, 2> wrapper_rel_4_A;
// -- Table: @delta_A
	std::unique_ptr<t_btree_2__0_1> rel_5_delta_A = std::make_unique<
			t_btree_2__0_1>();
// -- Table: @new_A
	std::unique_ptr<t_btree_2__0_1> rel_6_new_A = std::make_unique<
			t_btree_2__0_1>();
// -- Table: R
	std::unique_ptr<t_btree_2__0_1__3> rel_7_R = std::make_unique<
			t_btree_2__0_1__3>();
	souffle::RelationWrapper<4, t_btree_2__0_1__3, Tuple<RamDomain, 2>, 2> wrapper_rel_7_R;
// -- Table: @delta_R
	std::unique_ptr<t_btree_2__0_1> rel_8_delta_R = std::make_unique<
			t_btree_2__0_1>();
// -- Table: @new_R
	std::unique_ptr<t_btree_2__0_1> rel_9_new_R = std::make_unique<
			t_btree_2__0_1>();
// -- Table: P
	std::unique_ptr<t_btree_2__0_1__3> rel_10_P = std::make_unique<
			t_btree_2__0_1__3>();
	souffle::RelationWrapper<5, t_btree_2__0_1__3, Tuple<RamDomain, 2>, 2> wrapper_rel_10_P;
// -- Table: @delta_P
	std::unique_ptr<t_btree_2__0_1> rel_11_delta_P = std::make_unique<
			t_btree_2__0_1>();
// -- Table: @new_P
	std::unique_ptr<t_btree_2__0_1> rel_12_new_P = std::make_unique<
			t_btree_2__0_1>();
// -- Table: Q
	std::unique_ptr<t_btree_2__0_1__3> rel_13_Q = std::make_unique<
			t_btree_2__0_1__3>();
	souffle::RelationWrapper<6, t_btree_2__0_1__3, Tuple<RamDomain, 2>, 2> wrapper_rel_13_Q;
// -- Table: @delta_Q
	std::unique_ptr<t_btree_2__0_1__3> rel_14_delta_Q = std::make_unique<
			t_btree_2__0_1__3>();
// -- Table: @new_Q
	std::unique_ptr<t_btree_2__0_1__3> rel_15_new_Q = std::make_unique<
			t_btree_2__0_1__3>();
// -- Table: S
	std::unique_ptr<t_btree_2__0_1__3> rel_16_S = std::make_unique<
			t_btree_2__0_1__3>();
	souffle::RelationWrapper<7, t_btree_2__0_1__3, Tuple<RamDomain, 2>, 2> wrapper_rel_16_S;
// -- Table: @delta_S
	std::unique_ptr<t_btree_2__0_1> rel_17_delta_S = std::make_unique<
			t_btree_2__0_1>();
// -- Table: @new_S
	std::unique_ptr<t_btree_2__0_1> rel_18_new_S = std::make_unique<
			t_btree_2__0_1>();
public:
	Sf_const_prop() :
			wrapper_rel_1_B(*rel_1_B, symTable, "B",
					std::array<const char *, 2> { { "s:symbol",
							"e:Constant{Top:s:symbol,Bot:s:symbol}" } },
					std::array<const char *, 2> { { "x", "s" } }),

			wrapper_rel_2_C(*rel_2_C, symTable, "C",
					std::array<const char *, 2> { { "s:symbol",
							"e:Constant{Top:s:symbol,Bot:s:symbol}" } },
					std::array<const char *, 2> { { "x", "s" } }),

			wrapper_rel_3_D(*rel_3_D, symTable, "D",
					std::array<const char *, 2> { { "s:symbol",
							"e:Constant{Top:s:symbol,Bot:s:symbol}" } },
					std::array<const char *, 2> { { "x", "s" } }),

			wrapper_rel_4_A(*rel_4_A, symTable, "A",
					std::array<const char *, 2> { { "s:symbol",
							"e:Constant{Top:s:symbol,Bot:s:symbol}" } },
					std::array<const char *, 2> { { "x", "s" } }),

			wrapper_rel_7_R(*rel_7_R, symTable, "R",
					std::array<const char *, 2> { { "s:symbol",
							"e:Constant{Top:s:symbol,Bot:s:symbol}" } },
					std::array<const char *, 2> { { "x", "s" } }),

			wrapper_rel_10_P(*rel_10_P, symTable, "P",
					std::array<const char *, 2> { { "s:symbol", "s:symbol" } },
					std::array<const char *, 2> { { "x", "s" } }),

			wrapper_rel_13_Q(*rel_13_Q, symTable, "Q",
					std::array<const char *, 2> { { "s:symbol", "s:symbol" } },
					std::array<const char *, 2> { { "x", "s" } }),

			wrapper_rel_16_S(*rel_16_S, symTable, "S",
					std::array<const char *, 2> { { "s:symbol", "s:symbol" } },
					std::array<const char *, 2> { { "x", "s" } }) {
		addRelation("B", &wrapper_rel_1_B, true, false);
		addRelation("C", &wrapper_rel_2_C, true, false);
		addRelation("D", &wrapper_rel_3_D, true, false);
		addRelation("A", &wrapper_rel_4_A, true, false);
		addRelation("R", &wrapper_rel_7_R, false, true);
		addRelation("P", &wrapper_rel_10_P, true, false);
		addRelation("Q", &wrapper_rel_13_Q, true, false);
		addRelation("S", &wrapper_rel_16_S, false, true);
	}
	~Sf_const_prop() {
	}
private:
	void runFunction(std::string inputDirectory = ".",
			std::string outputDirectory = ".",
			size_t stratumIndex = (size_t) -1, bool performIO = false) {
		SignalHandler::instance()->set();
		std::atomic<size_t> iter(0);

#if defined(__EMBEDDED_SOUFFLE__) && defined(_OPENMP)
		omp_set_num_threads(1);
#endif

// -- query evaluation --
		/* BEGIN STRATUM 0 */
		[&]() {
			/* BEGIN visitSequence @Synthesiser.cpp:500 */
			/* BEGIN visitCreate @Synthesiser.cpp:234 */
			/* END visitCreate @Synthesiser.cpp:235 */
			/* BEGIN visitLoad @Synthesiser.cpp:246 */
			if (performIO) {
				try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","./B.facts"}, {"name","B"}});
					if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
					IODirectives ioDirectives(directiveMap);
					IOSystem::getInstance().getReader(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->readAll(*rel_1_B);
				} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
			}
			/* END visitLoad @Synthesiser.cpp:273 */
			/* END visitSequence @Synthesiser.cpp:504 */
		}();
		/* END STRATUM 0 */
		/* BEGIN STRATUM 1 */
		[&]() {
			/* BEGIN visitSequence @Synthesiser.cpp:500 */
			/* BEGIN visitCreate @Synthesiser.cpp:234 */
			/* END visitCreate @Synthesiser.cpp:235 */
			/* BEGIN visitLoad @Synthesiser.cpp:246 */
			if (performIO) {
				try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","./C.facts"}, {"name","C"}});
					if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
					IODirectives ioDirectives(directiveMap);
					IOSystem::getInstance().getReader(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->readAll(*rel_2_C);
				} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
			}
			/* END visitLoad @Synthesiser.cpp:273 */
			/* END visitSequence @Synthesiser.cpp:504 */
		}();
		/* END STRATUM 1 */
		/* BEGIN STRATUM 2 */
		[&]() {
			/* BEGIN visitSequence @Synthesiser.cpp:500 */
			/* BEGIN visitCreate @Synthesiser.cpp:234 */
			/* END visitCreate @Synthesiser.cpp:235 */
			/* BEGIN visitLoad @Synthesiser.cpp:246 */
			if (performIO) {
				try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","./D.facts"}, {"name","D"}});
					if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
					IODirectives ioDirectives(directiveMap);
					IOSystem::getInstance().getReader(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->readAll(*rel_3_D);
				} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
			}
			/* END visitLoad @Synthesiser.cpp:273 */
			/* END visitSequence @Synthesiser.cpp:504 */
		}();
		/* END STRATUM 2 */
		/* BEGIN STRATUM 3 */
		[&]() {
			/* BEGIN visitSequence @Synthesiser.cpp:500 */
			/* BEGIN visitCreate @Synthesiser.cpp:234 */
			/* END visitCreate @Synthesiser.cpp:235 */
			/* BEGIN visitCreate @Synthesiser.cpp:234 */
			/* END visitCreate @Synthesiser.cpp:235 */
			/* BEGIN visitCreate @Synthesiser.cpp:234 */
			/* END visitCreate @Synthesiser.cpp:235 */
			/* BEGIN visitCreate @Synthesiser.cpp:234 */
			/* END visitCreate @Synthesiser.cpp:235 */
			/* BEGIN visitCreate @Synthesiser.cpp:234 */
			/* END visitCreate @Synthesiser.cpp:235 */
			/* BEGIN visitCreate @Synthesiser.cpp:234 */
			/* END visitCreate @Synthesiser.cpp:235 */
			/* BEGIN visitLoad @Synthesiser.cpp:246 */
			if (performIO) {
				try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","./A.facts"}, {"name","A"}});
					if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
					IODirectives ioDirectives(directiveMap);
					IOSystem::getInstance().getReader(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->readAll(*rel_4_A);
				} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
			}
			/* END visitLoad @Synthesiser.cpp:273 */
			/* BEGIN visitSequence @Synthesiser.cpp:500 */
			/* BEGIN visitMerge @Synthesiser.cpp:447 */
			rel_5_delta_A->insertAll(*rel_4_A);
			/* END visitMerge @Synthesiser.cpp:459 */
			/* BEGIN visitMerge @Synthesiser.cpp:447 */
			rel_8_delta_R->insertAll(*rel_7_R);
			/* END visitMerge @Synthesiser.cpp:459 */
			/* BEGIN visitLoop @Synthesiser.cpp:543 */
			iter = 0;
			for(;;) {
				/* BEGIN visitSequence @Synthesiser.cpp:500 */
				/* BEGIN visitParallel @Synthesiser.cpp:509 */
				SECTIONS_START;
				SECTION_START;
				/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
				SignalHandler::instance()->setMsg(R"_(A(x,s) :- 
   R(x,s),
   B(x,s).
in file /home/gq/Programming/souffle/src/dataflowTest/lattice_Const/const_prop.dl [41:1-41:29])_");
				/* BEGIN visitInsert @Synthesiser.cpp:306 */
				if (!rel_8_delta_R->empty()&&!rel_1_B->empty()) [&]() {
					auto part = rel_8_delta_R->partition();
					PARALLEL_START;
					CREATE_OP_CONTEXT(rel_8_delta_R_op_ctxt,rel_8_delta_R->createContext());
					CREATE_OP_CONTEXT(rel_6_new_A_op_ctxt,rel_6_new_A->createContext());
					CREATE_OP_CONTEXT(rel_4_A_op_ctxt,rel_4_A->createContext());
					CREATE_OP_CONTEXT(rel_1_B_op_ctxt,rel_1_B->createContext());
					/* BEGIN visitScan @Synthesiser.cpp:640 */
					pfor(auto it = part.begin(); it<part.end();++it) {
						try {for(const auto& env0 : *it) {
								/* BEGIN visitSearch @Synthesiser.cpp:634 */
								/* BEGIN visitScan @Synthesiser.cpp:640 */
								for(const auto& env1 : *rel_1_B) {
									/* BEGIN visitSearch @Synthesiser.cpp:634 */
									/* BEGIN visitFilter @Synthesiser.cpp:950 */
									if( /* BEGIN visitNegation @Synthesiser.cpp:998 */
											!(/* BEGIN visitExistenceCheck @Synthesiser.cpp:1103 */
													rel_4_A->contains(Tuple<RamDomain,2>( { {/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																			env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
																			,/* BEGIN visitLatticeGLB @Synthesiser.cpp:1188 */
//TODO: visitLatticeGLB/* END visitLatticeGLB @Synthesiser.cpp:1190 */
																		}}),READ_OP_CONTEXT(rel_4_A_op_ctxt))/* END visitExistenceCheck @Synthesiser.cpp:1124 */
											)/* END visitNegation @Synthesiser.cpp:1002 */
									) {
										/* BEGIN visitFilter @Synthesiser.cpp:950 */
										if( /* BEGIN visitConstraint @Synthesiser.cpp:1007 */
												((/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
														) == (/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																env1[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
														))/* END visitConstraint @Synthesiser.cpp:1090 */
										) {
											/* BEGIN visitProject @Synthesiser.cpp:961 */
											Tuple<RamDomain,2> tuple( { {static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																	env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
															),static_cast<RamDomain>(/* BEGIN visitLatticeGLB @Synthesiser.cpp:1188 */
//TODO: visitLatticeGLB/* END visitLatticeGLB @Synthesiser.cpp:1190 */
															)}});
											rel_6_new_A->insert(tuple,READ_OP_CONTEXT(rel_6_new_A_op_ctxt));
											/* END visitProject @Synthesiser.cpp:981 */
										}
										/* END visitFilter @Synthesiser.cpp:956 */
									}
									/* END visitFilter @Synthesiser.cpp:956 */
									/* END visitSearch @Synthesiser.cpp:636 */
								}
								/* END visitScan @Synthesiser.cpp:694 */
								/* END visitSearch @Synthesiser.cpp:636 */
							}
						} catch(std::exception &e) {SignalHandler::instance()->error(e.what());}
					}
					/* END visitScan @Synthesiser.cpp:694 */
					PARALLEL_END;
				}
				();/* END visitInsert @Synthesiser.cpp:443 */
				/* END visitDebugInfo @Synthesiser.cpp:611 */
				SECTION_END
				SECTION_START;
				/* BEGIN visitSequence @Synthesiser.cpp:500 */
				/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
				SignalHandler::instance()->setMsg(R"_(R(x,s) :- 
   A(x,s),
   B(x,s),
   C(x,s).
in file /home/gq/Programming/souffle/src/dataflowTest/lattice_Const/const_prop.dl [40:1-40:38])_");
				/* BEGIN visitInsert @Synthesiser.cpp:306 */
				if (!rel_5_delta_A->empty()&&!rel_1_B->empty()&&!rel_2_C->empty()) [&]() {
					auto part = rel_5_delta_A->partition();
					PARALLEL_START;
					CREATE_OP_CONTEXT(rel_5_delta_A_op_ctxt,rel_5_delta_A->createContext());
					CREATE_OP_CONTEXT(rel_9_new_R_op_ctxt,rel_9_new_R->createContext());
					CREATE_OP_CONTEXT(rel_1_B_op_ctxt,rel_1_B->createContext());
					CREATE_OP_CONTEXT(rel_2_C_op_ctxt,rel_2_C->createContext());
					CREATE_OP_CONTEXT(rel_7_R_op_ctxt,rel_7_R->createContext());
					/* BEGIN visitScan @Synthesiser.cpp:640 */
					pfor(auto it = part.begin(); it<part.end();++it) {
						try {for(const auto& env0 : *it) {
								/* BEGIN visitSearch @Synthesiser.cpp:634 */
								/* BEGIN visitScan @Synthesiser.cpp:640 */
								for(const auto& env1 : *rel_1_B) {
									/* BEGIN visitSearch @Synthesiser.cpp:634 */
									/* BEGIN visitScan @Synthesiser.cpp:640 */
									for(const auto& env2 : *rel_2_C) {
										/* BEGIN visitSearch @Synthesiser.cpp:634 */
										/* BEGIN visitFilter @Synthesiser.cpp:950 */
										if( /* BEGIN visitNegation @Synthesiser.cpp:998 */
												!(/* BEGIN visitExistenceCheck @Synthesiser.cpp:1103 */
														rel_7_R->contains(Tuple<RamDomain,2>( { {/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																				env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
																				,/* BEGIN visitLatticeGLB @Synthesiser.cpp:1188 */
//TODO: visitLatticeGLB/* END visitLatticeGLB @Synthesiser.cpp:1190 */
																			}}),READ_OP_CONTEXT(rel_7_R_op_ctxt))/* END visitExistenceCheck @Synthesiser.cpp:1124 */
												)/* END visitNegation @Synthesiser.cpp:1002 */
										) {
											/* BEGIN visitFilter @Synthesiser.cpp:950 */
											if( /* BEGIN visitConstraint @Synthesiser.cpp:1007 */
													((/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																	env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
															) == (/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																	env2[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
															))/* END visitConstraint @Synthesiser.cpp:1090 */
											) {
												/* BEGIN visitFilter @Synthesiser.cpp:950 */
												if( /* BEGIN visitConstraint @Synthesiser.cpp:1007 */
														((/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																		env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
																) == (/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																		env1[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
																))/* END visitConstraint @Synthesiser.cpp:1090 */
												) {
													/* BEGIN visitProject @Synthesiser.cpp:961 */
													Tuple<RamDomain,2> tuple( { {static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																			env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
																	),static_cast<RamDomain>(/* BEGIN visitLatticeGLB @Synthesiser.cpp:1188 */
//TODO: visitLatticeGLB/* END visitLatticeGLB @Synthesiser.cpp:1190 */
																	)}});
													rel_9_new_R->insert(tuple,READ_OP_CONTEXT(rel_9_new_R_op_ctxt));
													/* END visitProject @Synthesiser.cpp:981 */
												}
												/* END visitFilter @Synthesiser.cpp:956 */
											}
											/* END visitFilter @Synthesiser.cpp:956 */
										}
										/* END visitFilter @Synthesiser.cpp:956 */
										/* END visitSearch @Synthesiser.cpp:636 */
									}
									/* END visitScan @Synthesiser.cpp:694 */
									/* END visitSearch @Synthesiser.cpp:636 */
								}
								/* END visitScan @Synthesiser.cpp:694 */
								/* END visitSearch @Synthesiser.cpp:636 */
							}
						} catch(std::exception &e) {SignalHandler::instance()->error(e.what());}
					}
					/* END visitScan @Synthesiser.cpp:694 */
					PARALLEL_END;
				}();/* END visitInsert @Synthesiser.cpp:443 */
				/* END visitDebugInfo @Synthesiser.cpp:611 */
				/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
				SignalHandler::instance()->setMsg(
						R"_(R(x,s) :- 
   A(x,s),
   D(x,s).
in file /home/gq/Programming/souffle/src/dataflowTest/lattice_Const/const_prop.dl [42:1-42:29])_");
				/* BEGIN visitInsert @Synthesiser.cpp:306 */
				if (!rel_5_delta_A->empty()&&!rel_3_D->empty()) [&]() {
					auto part = rel_5_delta_A->partition();
					PARALLEL_START;
					CREATE_OP_CONTEXT(rel_5_delta_A_op_ctxt,rel_5_delta_A->createContext());
					CREATE_OP_CONTEXT(rel_9_new_R_op_ctxt,rel_9_new_R->createContext());
					CREATE_OP_CONTEXT(rel_3_D_op_ctxt,rel_3_D->createContext());
					CREATE_OP_CONTEXT(rel_7_R_op_ctxt,rel_7_R->createContext());
					/* BEGIN visitScan @Synthesiser.cpp:640 */
					pfor(auto it = part.begin(); it<part.end();++it) {
						try {for(const auto& env0 : *it) {
								/* BEGIN visitSearch @Synthesiser.cpp:634 */
								/* BEGIN visitScan @Synthesiser.cpp:640 */
								for(const auto& env1 : *rel_3_D) {
									/* BEGIN visitSearch @Synthesiser.cpp:634 */
									/* BEGIN visitFilter @Synthesiser.cpp:950 */
									if( /* BEGIN visitNegation @Synthesiser.cpp:998 */
											!(/* BEGIN visitExistenceCheck @Synthesiser.cpp:1103 */
													rel_7_R->contains(Tuple<RamDomain,2>( { {/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																			env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
																			,/* BEGIN visitLatticeGLB @Synthesiser.cpp:1188 */
//TODO: visitLatticeGLB/* END visitLatticeGLB @Synthesiser.cpp:1190 */
																		}}),READ_OP_CONTEXT(rel_7_R_op_ctxt))/* END visitExistenceCheck @Synthesiser.cpp:1124 */
											)/* END visitNegation @Synthesiser.cpp:1002 */
									) {
										/* BEGIN visitFilter @Synthesiser.cpp:950 */
										if( /* BEGIN visitConstraint @Synthesiser.cpp:1007 */
												((/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
														) == (/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																env1[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
														))/* END visitConstraint @Synthesiser.cpp:1090 */
										) {
											/* BEGIN visitProject @Synthesiser.cpp:961 */
											Tuple<RamDomain,2> tuple( { {static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																	env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
															),static_cast<RamDomain>(/* BEGIN visitLatticeGLB @Synthesiser.cpp:1188 */
//TODO: visitLatticeGLB/* END visitLatticeGLB @Synthesiser.cpp:1190 */
															)}});
											rel_9_new_R->insert(tuple,READ_OP_CONTEXT(rel_9_new_R_op_ctxt));
											/* END visitProject @Synthesiser.cpp:981 */
										}
										/* END visitFilter @Synthesiser.cpp:956 */
									}
									/* END visitFilter @Synthesiser.cpp:956 */
									/* END visitSearch @Synthesiser.cpp:636 */
								}
								/* END visitScan @Synthesiser.cpp:694 */
								/* END visitSearch @Synthesiser.cpp:636 */
							}
						} catch(std::exception &e) {SignalHandler::instance()->error(e.what());}
					}
					/* END visitScan @Synthesiser.cpp:694 */
				PARALLEL_END
				;
			}
();/* END visitInsert @Synthesiser.cpp:443 */
/* END visitDebugInfo @Synthesiser.cpp:611 */
/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
SignalHandler::instance()->setMsg(R"_(R(x,s) :- 
   A(x,s),
   C(x,s).
in file /home/gq/Programming/souffle/src/dataflowTest/lattice_Const/const_prop.dl [43:1-43:29])_");
/* BEGIN visitInsert @Synthesiser.cpp:306 */
if (!rel_5_delta_A->empty()&&!rel_2_C->empty()) [&](){
auto part = rel_5_delta_A->partition();
PARALLEL_START;
			CREATE_OP_CONTEXT(rel_5_delta_A_op_ctxt,
					rel_5_delta_A->createContext());CREATE_OP_CONTEXT(
					rel_9_new_R_op_ctxt, rel_9_new_R->createContext());CREATE_OP_CONTEXT(
					rel_2_C_op_ctxt, rel_2_C->createContext());CREATE_OP_CONTEXT(
					rel_7_R_op_ctxt, rel_7_R->createContext());
			/* BEGIN visitScan @Synthesiser.cpp:640 */
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
/* BEGIN visitSearch @Synthesiser.cpp:634 */
/* BEGIN visitScan @Synthesiser.cpp:640 */
for(const auto& env1 : *rel_2_C) {
/* BEGIN visitSearch @Synthesiser.cpp:634 */
/* BEGIN visitFilter @Synthesiser.cpp:950 */
if( /* BEGIN visitNegation @Synthesiser.cpp:998 */
!(/* BEGIN visitExistenceCheck @Synthesiser.cpp:1103 */
rel_7_R->contains(Tuple<RamDomain,2>({{/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
,/* BEGIN visitLatticeGLB @Synthesiser.cpp:1188 */
//TODO: visitLatticeGLB/* END visitLatticeGLB @Synthesiser.cpp:1190 */
}}),			READ_OP_CONTEXT(rel_7_R_op_ctxt))/* END visitExistenceCheck @Synthesiser.cpp:1124 */
)/* END visitNegation @Synthesiser.cpp:1002 */
) {
/* BEGIN visitFilter @Synthesiser.cpp:950 */
if( /* BEGIN visitConstraint @Synthesiser.cpp:1007 */
((/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
) == (/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env1[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
))/* END visitConstraint @Synthesiser.cpp:1090 */
) {
/* BEGIN visitProject @Synthesiser.cpp:961 */
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
),static_cast<RamDomain>(/* BEGIN visitLatticeGLB @Synthesiser.cpp:1188 */
//TODO: visitLatticeGLB/* END visitLatticeGLB @Synthesiser.cpp:1190 */
)}});
rel_9_new_R->insert(tuple,READ_OP_CONTEXT(rel_9_new_R_op_ctxt)
			);
			/* END visitProject @Synthesiser.cpp:981 */
		}
		/* END visitFilter @Synthesiser.cpp:956 */
	}
	/* END visitFilter @Synthesiser.cpp:956 */
	/* END visitSearch @Synthesiser.cpp:636 */
}
/* END visitScan @Synthesiser.cpp:694 */
/* END visitSearch @Synthesiser.cpp:636 */
}
} catch(std::exception &e) {SignalHandler::instance()->error(e.what());}
}
/* END visitScan @Synthesiser.cpp:694 */
PARALLEL_END;
}
();/* END visitInsert @Synthesiser.cpp:443 */
/* END visitDebugInfo @Synthesiser.cpp:611 */
/* END visitSequence @Synthesiser.cpp:504 */
SECTION_END
SECTIONS_END;
/* END visitParallel @Synthesiser.cpp:539 */
/* BEGIN visitExit @Synthesiser.cpp:566 */
if(/* BEGIN visitConjunction @Synthesiser.cpp:988 */
((/* BEGIN visitEmptinessCheck @Synthesiser.cpp:1095 */
		rel_6_new_A->empty()/* END visitEmptinessCheck @Synthesiser.cpp:1098 */
) && (/* BEGIN visitEmptinessCheck @Synthesiser.cpp:1095 */
		rel_9_new_R->empty()/* END visitEmptinessCheck @Synthesiser.cpp:1098 */
))/* END visitConjunction @Synthesiser.cpp:994 */
) break;
/* END visitExit @Synthesiser.cpp:570 */
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitMerge @Synthesiser.cpp:447 */
rel_4_A->insertAll(*rel_6_new_A);
/* END visitMerge @Synthesiser.cpp:459 */
/* BEGIN visitLatNorm @Synthesiser.cpp:465 */
//TODO: visitLatNorm/* END visitLatNorm @Synthesiser.cpp:467 */
/* BEGIN visitSwap @Synthesiser.cpp:554 */
std::swap(rel_5_delta_A, rel_6_new_A);
/* END visitSwap @Synthesiser.cpp:562 */
/* BEGIN visitClear @Synthesiser.cpp:471 */
rel_6_new_A->purge();
/* END visitClear @Synthesiser.cpp:474 */
/* END visitSequence @Synthesiser.cpp:504 */
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitMerge @Synthesiser.cpp:447 */
rel_7_R->insertAll(*rel_9_new_R);
/* END visitMerge @Synthesiser.cpp:459 */
/* BEGIN visitLatNorm @Synthesiser.cpp:465 */
//TODO: visitLatNorm/* END visitLatNorm @Synthesiser.cpp:467 */
/* BEGIN visitSwap @Synthesiser.cpp:554 */
std::swap(rel_8_delta_R, rel_9_new_R);
/* END visitSwap @Synthesiser.cpp:562 */
/* BEGIN visitClear @Synthesiser.cpp:471 */
rel_9_new_R->purge();
/* END visitClear @Synthesiser.cpp:474 */
/* END visitSequence @Synthesiser.cpp:504 */
/* END visitSequence @Synthesiser.cpp:504 */
/* END visitSequence @Synthesiser.cpp:504 */
iter++;
}
iter = 0;
/* END visitLoop @Synthesiser.cpp:550 */
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_5_delta_A->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_6_new_A->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_8_delta_R->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_9_new_R->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* END visitSequence @Synthesiser.cpp:504 */
/* END visitSequence @Synthesiser.cpp:504 */
/* END visitSequence @Synthesiser.cpp:504 */
/* BEGIN visitStore @Synthesiser.cpp:277 */
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","x\ts"},{"filename","./R.csv"},{"name","R"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask({1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_7_R);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
/* END visitStore @Synthesiser.cpp:302 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_4_A->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_1_B->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_2_C->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_3_D->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_7_R->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* END visitSequence @Synthesiser.cpp:504 */
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitCreate @Synthesiser.cpp:234 */
/* END visitCreate @Synthesiser.cpp:235 */
/* BEGIN visitCreate @Synthesiser.cpp:234 */
/* END visitCreate @Synthesiser.cpp:235 */
/* BEGIN visitCreate @Synthesiser.cpp:234 */
/* END visitCreate @Synthesiser.cpp:235 */
/* BEGIN visitCreate @Synthesiser.cpp:234 */
/* END visitCreate @Synthesiser.cpp:235 */
/* BEGIN visitCreate @Synthesiser.cpp:234 */
/* END visitCreate @Synthesiser.cpp:235 */
/* BEGIN visitCreate @Synthesiser.cpp:234 */
/* END visitCreate @Synthesiser.cpp:235 */
/* BEGIN visitCreate @Synthesiser.cpp:234 */
/* END visitCreate @Synthesiser.cpp:235 */
/* BEGIN visitCreate @Synthesiser.cpp:234 */
/* END visitCreate @Synthesiser.cpp:235 */
/* BEGIN visitCreate @Synthesiser.cpp:234 */
/* END visitCreate @Synthesiser.cpp:235 */
/* BEGIN visitLoad @Synthesiser.cpp:246 */
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./P.facts"},{"name","P"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({1, 1}), symTable, ioDirectives, 0)->readAll(*rel_10_P);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
/* END visitLoad @Synthesiser.cpp:273 */
/* BEGIN visitLoad @Synthesiser.cpp:246 */
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Q.facts"},{"name","Q"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask({1, 1}), symTable, ioDirectives, 0)->readAll(*rel_13_Q);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
/* END visitLoad @Synthesiser.cpp:273 */
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitMerge @Synthesiser.cpp:447 */
rel_11_delta_P->insertAll(*rel_10_P);
/* END visitMerge @Synthesiser.cpp:459 */
/* BEGIN visitMerge @Synthesiser.cpp:447 */
rel_14_delta_Q->insertAll(*rel_13_Q);
/* END visitMerge @Synthesiser.cpp:459 */
/* BEGIN visitMerge @Synthesiser.cpp:447 */
rel_17_delta_S->insertAll(*rel_16_S);
/* END visitMerge @Synthesiser.cpp:459 */
/* BEGIN visitLoop @Synthesiser.cpp:543 */
iter = 0;
for(;;) {
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitParallel @Synthesiser.cpp:509 */
SECTIONS_START;
SECTION_START;
/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
SignalHandler::instance()->setMsg(R"_(P(x,s) :- 
   S(x,s).
in file /home/gq/Programming/souffle/src/dataflowTest/lattice_Const/const_prop.dl [53:1-53:20])_");
/* BEGIN visitInsert @Synthesiser.cpp:306 */
if (!rel_17_delta_S->empty()) [&](){
auto part = rel_17_delta_S->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_17_delta_S_op_ctxt, rel_17_delta_S->createContext());CREATE_OP_CONTEXT(
rel_12_new_P_op_ctxt, rel_12_new_P->createContext());CREATE_OP_CONTEXT(
rel_10_P_op_ctxt, rel_10_P->createContext());
/* BEGIN visitScan @Synthesiser.cpp:640 */
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
/* BEGIN visitSearch @Synthesiser.cpp:634 */
/* BEGIN visitFilter @Synthesiser.cpp:950 */
if( /* BEGIN visitNegation @Synthesiser.cpp:998 */
!(/* BEGIN visitExistenceCheck @Synthesiser.cpp:1103 */
rel_10_P->contains(Tuple<RamDomain,2>({{/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
,/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
}}),READ_OP_CONTEXT(rel_10_P_op_ctxt))/* END visitExistenceCheck @Synthesiser.cpp:1124 */
)/* END visitNegation @Synthesiser.cpp:1002 */
) {
/* BEGIN visitProject @Synthesiser.cpp:961 */
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
),static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
)}});
rel_12_new_P->insert(tuple,READ_OP_CONTEXT(rel_12_new_P_op_ctxt));
/* END visitProject @Synthesiser.cpp:981 */
}
/* END visitFilter @Synthesiser.cpp:956 */
/* END visitSearch @Synthesiser.cpp:636 */
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
/* END visitScan @Synthesiser.cpp:694 */
PARALLEL_END;
}
();/* END visitInsert @Synthesiser.cpp:443 */
/* END visitDebugInfo @Synthesiser.cpp:611 */
SECTION_END
SECTION_START;
/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
SignalHandler::instance()->setMsg(R"_(Q(x,s) :- 
   P(x,s).
in file /home/gq/Programming/souffle/src/dataflowTest/lattice_Const/const_prop.dl [54:1-54:20])_");
/* BEGIN visitInsert @Synthesiser.cpp:306 */
if (!rel_11_delta_P->empty()) [&](){
auto part = rel_11_delta_P->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(
rel_11_delta_P_op_ctxt, rel_11_delta_P->createContext());CREATE_OP_CONTEXT(
rel_15_new_Q_op_ctxt, rel_15_new_Q->createContext());CREATE_OP_CONTEXT(
rel_13_Q_op_ctxt, rel_13_Q->createContext());
/* BEGIN visitScan @Synthesiser.cpp:640 */
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
/* BEGIN visitSearch @Synthesiser.cpp:634 */
/* BEGIN visitFilter @Synthesiser.cpp:950 */
if( /* BEGIN visitNegation @Synthesiser.cpp:998 */
!(/* BEGIN visitExistenceCheck @Synthesiser.cpp:1103 */
rel_13_Q->contains(Tuple<RamDomain,2>({{/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
,/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
}}),READ_OP_CONTEXT(rel_13_Q_op_ctxt))/* END visitExistenceCheck @Synthesiser.cpp:1124 */
)/* END visitNegation @Synthesiser.cpp:1002 */
) {
/* BEGIN visitProject @Synthesiser.cpp:961 */
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
),static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
)}});
rel_15_new_Q->insert(tuple,READ_OP_CONTEXT(rel_15_new_Q_op_ctxt));
/* END visitProject @Synthesiser.cpp:981 */
}
/* END visitFilter @Synthesiser.cpp:956 */
/* END visitSearch @Synthesiser.cpp:636 */
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
/* END visitScan @Synthesiser.cpp:694 */
PARALLEL_END;
}
();/* END visitInsert @Synthesiser.cpp:443 */
/* END visitDebugInfo @Synthesiser.cpp:611 */
SECTION_END
SECTION_START;
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
SignalHandler::instance()->setMsg(R"_(S(x,s) :- 
   P(x,s),
   Q(x,s).
in file /home/gq/Programming/souffle/src/dataflowTest/lattice_Const/const_prop.dl [52:1-52:29])_");
/* BEGIN visitInsert @Synthesiser.cpp:306 */
if (!rel_11_delta_P->empty()&&!rel_13_Q->empty()) [&](){
auto part = rel_11_delta_P->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(
rel_11_delta_P_op_ctxt, rel_11_delta_P->createContext());CREATE_OP_CONTEXT(
rel_14_delta_Q_op_ctxt, rel_14_delta_Q->createContext());CREATE_OP_CONTEXT(
rel_18_new_S_op_ctxt, rel_18_new_S->createContext());CREATE_OP_CONTEXT(
rel_13_Q_op_ctxt, rel_13_Q->createContext());CREATE_OP_CONTEXT(rel_16_S_op_ctxt,
rel_16_S->createContext());
/* BEGIN visitScan @Synthesiser.cpp:640 */
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
/* BEGIN visitSearch @Synthesiser.cpp:634 */
/* BEGIN visitScan @Synthesiser.cpp:640 */
for(const auto& env1 : *rel_13_Q) {
/* BEGIN visitSearch @Synthesiser.cpp:634 */
/* BEGIN visitFilter @Synthesiser.cpp:950 */
if( /* BEGIN visitNegation @Synthesiser.cpp:998 */
!(/* BEGIN visitExistenceCheck @Synthesiser.cpp:1103 */
rel_14_delta_Q->contains(Tuple<RamDomain,2>({{/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
,/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
}}),READ_OP_CONTEXT(rel_14_delta_Q_op_ctxt))/* END visitExistenceCheck @Synthesiser.cpp:1124 */
)/* END visitNegation @Synthesiser.cpp:1002 */
) {
/* BEGIN visitFilter @Synthesiser.cpp:950 */
if( /* BEGIN visitNegation @Synthesiser.cpp:998 */
!(/* BEGIN visitExistenceCheck @Synthesiser.cpp:1103 */
rel_16_S->contains(Tuple<RamDomain,2>({{/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
,/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
}}),READ_OP_CONTEXT(rel_16_S_op_ctxt))/* END visitExistenceCheck @Synthesiser.cpp:1124 */
)/* END visitNegation @Synthesiser.cpp:1002 */
) {
/* BEGIN visitFilter @Synthesiser.cpp:950 */
if( /* BEGIN visitConstraint @Synthesiser.cpp:1007 */
((/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
) == (/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env1[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
))/* END visitConstraint @Synthesiser.cpp:1090 */
) {
/* BEGIN visitFilter @Synthesiser.cpp:950 */
if( /* BEGIN visitConstraint @Synthesiser.cpp:1007 */
((/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
) == (/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env1[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
))/* END visitConstraint @Synthesiser.cpp:1090 */
) {
/* BEGIN visitProject @Synthesiser.cpp:961 */
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
),static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
)}});
rel_18_new_S->insert(tuple,READ_OP_CONTEXT(
rel_18_new_S_op_ctxt));
/* END visitProject @Synthesiser.cpp:981 */
}
/* END visitFilter @Synthesiser.cpp:956 */
}
/* END visitFilter @Synthesiser.cpp:956 */
}
/* END visitFilter @Synthesiser.cpp:956 */
}
/* END visitFilter @Synthesiser.cpp:956 */
/* END visitSearch @Synthesiser.cpp:636 */
}
/* END visitScan @Synthesiser.cpp:694 */
/* END visitSearch @Synthesiser.cpp:636 */
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
/* END visitScan @Synthesiser.cpp:694 */
PARALLEL_END;
}
();/* END visitInsert @Synthesiser.cpp:443 */
/* END visitDebugInfo @Synthesiser.cpp:611 */
/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
SignalHandler::instance()->setMsg(R"_(S(x,s) :- 
   P(x,s),
   Q(x,s).
in file /home/gq/Programming/souffle/src/dataflowTest/lattice_Const/const_prop.dl [52:1-52:29])_");
/* BEGIN visitInsert @Synthesiser.cpp:306 */
if (!rel_14_delta_Q->empty()&&!rel_10_P->empty()) [&](){
auto part = rel_10_P->partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_14_delta_Q_op_ctxt,
rel_14_delta_Q->createContext());CREATE_OP_CONTEXT(rel_18_new_S_op_ctxt,
rel_18_new_S->createContext());CREATE_OP_CONTEXT(rel_10_P_op_ctxt,
rel_10_P->createContext());CREATE_OP_CONTEXT(rel_16_S_op_ctxt,
rel_16_S->createContext());
/* BEGIN visitScan @Synthesiser.cpp:640 */
pfor(auto it = part.begin(); it<part.end();++it){
try{for(const auto& env0 : *it) {
/* BEGIN visitSearch @Synthesiser.cpp:634 */
/* BEGIN visitScan @Synthesiser.cpp:640 */
for(const auto& env1 : *rel_14_delta_Q) {
/* BEGIN visitSearch @Synthesiser.cpp:634 */
/* BEGIN visitFilter @Synthesiser.cpp:950 */
if( /* BEGIN visitNegation @Synthesiser.cpp:998 */
!(/* BEGIN visitExistenceCheck @Synthesiser.cpp:1103 */
rel_16_S->contains(Tuple<RamDomain,2>({{/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
,/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
}}),READ_OP_CONTEXT(rel_16_S_op_ctxt))/* END visitExistenceCheck @Synthesiser.cpp:1124 */
)/* END visitNegation @Synthesiser.cpp:1002 */
) {
/* BEGIN visitFilter @Synthesiser.cpp:950 */
if( /* BEGIN visitConstraint @Synthesiser.cpp:1007 */
((/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
) == (/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env1[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
))/* END visitConstraint @Synthesiser.cpp:1090 */
) {
/* BEGIN visitFilter @Synthesiser.cpp:950 */
if( /* BEGIN visitConstraint @Synthesiser.cpp:1007 */
((/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
) == (/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env1[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
))/* END visitConstraint @Synthesiser.cpp:1090 */
) {
/* BEGIN visitProject @Synthesiser.cpp:961 */
Tuple<RamDomain,2> tuple({{static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
),static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
)}});
rel_18_new_S->insert(tuple,READ_OP_CONTEXT(rel_18_new_S_op_ctxt)
);
/* END visitProject @Synthesiser.cpp:981 */
}
/* END visitFilter @Synthesiser.cpp:956 */
}
/* END visitFilter @Synthesiser.cpp:956 */
}
/* END visitFilter @Synthesiser.cpp:956 */
/* END visitSearch @Synthesiser.cpp:636 */
}
/* END visitScan @Synthesiser.cpp:694 */
/* END visitSearch @Synthesiser.cpp:636 */
}
} catch(std::exception &e) {SignalHandler::instance()->error(e.what());}
}
/* END visitScan @Synthesiser.cpp:694 */
PARALLEL_END;
}
();/* END visitInsert @Synthesiser.cpp:443 */
/* END visitDebugInfo @Synthesiser.cpp:611 */
/* END visitSequence @Synthesiser.cpp:504 */
SECTION_END
SECTIONS_END;
/* END visitParallel @Synthesiser.cpp:539 */
/* BEGIN visitExit @Synthesiser.cpp:566 */
if(/* BEGIN visitConjunction @Synthesiser.cpp:988 */
((/* BEGIN visitConjunction @Synthesiser.cpp:988 */
((/* BEGIN visitEmptinessCheck @Synthesiser.cpp:1095 */
rel_12_new_P->empty()/* END visitEmptinessCheck @Synthesiser.cpp:1098 */
) && (/* BEGIN visitEmptinessCheck @Synthesiser.cpp:1095 */
rel_15_new_Q->empty()/* END visitEmptinessCheck @Synthesiser.cpp:1098 */
))/* END visitConjunction @Synthesiser.cpp:994 */
) && (/* BEGIN visitEmptinessCheck @Synthesiser.cpp:1095 */
rel_18_new_S->empty()/* END visitEmptinessCheck @Synthesiser.cpp:1098 */
))/* END visitConjunction @Synthesiser.cpp:994 */
) break;
/* END visitExit @Synthesiser.cpp:570 */
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitMerge @Synthesiser.cpp:447 */
rel_10_P->insertAll(*rel_12_new_P);
/* END visitMerge @Synthesiser.cpp:459 */
/* BEGIN visitSwap @Synthesiser.cpp:554 */
std::swap(rel_11_delta_P, rel_12_new_P);
/* END visitSwap @Synthesiser.cpp:562 */
/* BEGIN visitClear @Synthesiser.cpp:471 */
rel_12_new_P->purge();
/* END visitClear @Synthesiser.cpp:474 */
/* END visitSequence @Synthesiser.cpp:504 */
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitMerge @Synthesiser.cpp:447 */
rel_13_Q->insertAll(*rel_15_new_Q);
/* END visitMerge @Synthesiser.cpp:459 */
/* BEGIN visitSwap @Synthesiser.cpp:554 */
std::swap(rel_14_delta_Q, rel_15_new_Q);
/* END visitSwap @Synthesiser.cpp:562 */
/* BEGIN visitClear @Synthesiser.cpp:471 */
rel_15_new_Q->purge();
/* END visitClear @Synthesiser.cpp:474 */
/* END visitSequence @Synthesiser.cpp:504 */
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitMerge @Synthesiser.cpp:447 */
rel_16_S->insertAll(*rel_18_new_S);
/* END visitMerge @Synthesiser.cpp:459 */
/* BEGIN visitSwap @Synthesiser.cpp:554 */
std::swap(rel_17_delta_S, rel_18_new_S);
/* END visitSwap @Synthesiser.cpp:562 */
/* BEGIN visitClear @Synthesiser.cpp:471 */
rel_18_new_S->purge();
/* END visitClear @Synthesiser.cpp:474 */
/* END visitSequence @Synthesiser.cpp:504 */
/* END visitSequence @Synthesiser.cpp:504 */
/* END visitSequence @Synthesiser.cpp:504 */
iter++;
}
iter = 0;
/* END visitLoop @Synthesiser.cpp:550 */
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_11_delta_P->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_12_new_P->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_14_delta_Q->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_15_new_Q->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* END visitSequence @Synthesiser.cpp:504 */
/* BEGIN visitSequence @Synthesiser.cpp:500 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_17_delta_S->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 1)) rel_18_new_S->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* END visitSequence @Synthesiser.cpp:504 */
/* END visitSequence @Synthesiser.cpp:504 */
/* END visitSequence @Synthesiser.cpp:504 */
/* BEGIN visitStore @Synthesiser.cpp:277 */
if (performIO) {
try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"attributeNames","x\ts"}, {"filename","./S.csv"}, {"name","S"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_16_S);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
/* END visitStore @Synthesiser.cpp:302 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_10_P->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_13_Q->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* BEGIN visitDrop @Synthesiser.cpp:478 */
if (!isHintsProfilingEnabled() && (performIO || 0)) rel_16_S->purge();
/* END visitDrop @Synthesiser.cpp:485 */
/* END visitSequence @Synthesiser.cpp:504 */
}();
/* END STRATUM 4 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_B:\n";
rel_1_B->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_C:\n";
rel_2_C->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_D:\n";
rel_3_D->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_A:\n";
rel_4_A->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_delta_A:\n";
rel_5_delta_A->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_new_A:\n";
rel_6_new_A->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_R:\n";
rel_7_R->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_delta_R:\n";
rel_8_delta_R->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_new_R:\n";
rel_9_new_R->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_P:\n";
rel_10_P->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_delta_P:\n";
rel_11_delta_P->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_new_P:\n";
rel_12_new_P->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_13_Q:\n";
rel_13_Q->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_14_delta_Q:\n";
rel_14_delta_Q->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_15_new_Q:\n";
rel_15_new_Q->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_16_S:\n";
rel_16_S->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_17_delta_S:\n";
rel_17_delta_S->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_18_new_S:\n";
rel_18_new_S->printHintStatistics(std::cout,"  ");
std::cout << "\n";
}
SignalHandler::instance()->reset();
}
public:
void run(size_t stratumIndex = (size_t) -1) override {runFunction(".", ".", stratumIndex, false);}
public:
void runAll(std::string inputDirectory = ".", std::string outputDirectory = ".", size_t stratumIndex = (size_t) -1) override {runFunction(inputDirectory, outputDirectory, stratumIndex, true);
}
public:
void printAll(std::string outputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"attributeNames","x\ts"}, {"filename","./R.csv"}, {"name","R"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_7_R);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"attributeNames","x\ts"}, {"filename","./S.csv"}, {"name","S"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_16_S);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","./B.facts"}, {"name","B"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->readAll(*rel_1_B);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","./C.facts"}, {"name","C"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->readAll(*rel_2_C);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","./D.facts"}, {"name","D"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->readAll(*rel_3_D);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","./A.facts"}, {"name","A"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->readAll(*rel_4_A);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","./P.facts"}, {"name","P"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->readAll(*rel_10_P);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","./Q.facts"}, {"name","Q"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->readAll(*rel_13_Q);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_B");
IOSystem::getInstance().getWriter(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_1_B);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_C");
IOSystem::getInstance().getWriter(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_2_C);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_D");
IOSystem::getInstance().getWriter(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_3_D);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_4_A");
IOSystem::getInstance().getWriter(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_4_A);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_10_P");
IOSystem::getInstance().getWriter(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_10_P);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_13_Q");
IOSystem::getInstance().getWriter(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_13_Q);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_7_R");
IOSystem::getInstance().getWriter(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_7_R);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_16_S");
IOSystem::getInstance().getWriter(SymbolMask( {1, 1}), symTable, ioDirectives, 0)->writeAll(*rel_16_S);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
const SymbolTable &getSymbolTable() const override {
return symTable;
}
};
SouffleProgram *newInstance_const_prop() {
return new Sf_const_prop;
}
SymbolTable *getST_const_prop(SouffleProgram *p) {
return &reinterpret_cast<Sf_const_prop*>(p)->symTable;
}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_const_prop: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_const_prop();
};
public:
factory_Sf_const_prop() : ProgramFactory("const_prop") {}
};
static factory_Sf_const_prop __factory_Sf_const_prop_instance;
}
#else
}
int main(int argc, char** argv) {
try {
souffle::CmdOptions opt(R"(const_prop.dl)", R"(.)", R"(.)", false, R"()", 1,
-1);
if (!opt.parse(argc, argv))
return 1;
#if defined(_OPENMP) 
omp_set_nested(true);

#endif
souffle::Sf_const_prop obj;
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(),
opt.getStratumIndex());
return 0;
} catch (std::exception &e) {
souffle::SignalHandler::instance()->error(e.what());
}
}

#endif
