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
struct t_btree_1__0 {
	using t_tuple = Tuple<RamDomain, 1>;
	using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0>>;
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
		RamDomain data[1];
		std::copy(ramDomain, ramDomain + 1, data);
		const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
		context h;
		return insert(tuple, h);
	}
	bool insert(RamDomain a0) {
		RamDomain data[1] = { a0 };
		return insert(data);
	}
	template<typename T>
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
		o << prefix << "arity 1 direct b-tree index [0]: (hits/misses/total)\n";
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
struct t_btree_3__0_1_2__7 {
	using t_tuple = Tuple<RamDomain, 3>;
	using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2>>;
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
		RamDomain data[3];
		std::copy(ramDomain, ramDomain + 3, data);
		const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
		context h;
		return insert(tuple, h);
	}
	bool insert(RamDomain a0, RamDomain a1, RamDomain a2) {
		RamDomain data[3] = { a0, a1, a2 };
		return insert(data);
	}
	template<typename T>
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
		return range<iterator>(ind_0.begin(), ind_0.end());
	}
	range<t_ind_0::iterator> equalRange_7(const t_tuple& t, context& h) const {
		auto pos = ind_0.find(t, h.hints_0);
		auto fin = ind_0.end();
		if (pos != fin) {
			fin = pos;
			++fin;
		}
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
	void printHintStatistics(std::ostream& o, const std::string prefix) const {
		const auto& stats_0 = ind_0.getHintStatistics();
		o << prefix
				<< "arity 3 direct b-tree index [0,1,2]: (hits/misses/total)\n";
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
struct t_btree_3__0_1_2 {
	using t_tuple = Tuple<RamDomain, 3>;
	using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2>>;
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
		RamDomain data[3];
		std::copy(ramDomain, ramDomain + 3, data);
		const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
		context h;
		return insert(tuple, h);
	}
	bool insert(RamDomain a0, RamDomain a1, RamDomain a2) {
		RamDomain data[3] = { a0, a1, a2 };
		return insert(data);
	}
	template<typename T>
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
				<< "arity 3 direct b-tree index [0,1,2]: (hits/misses/total)\n";
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

class Sf_reachingDef: public SouffleProgram {
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
	SymbolTable symTable; // -- Table: assign
	std::unique_ptr<t_btree_2__0_1__3> rel_1_assign = std::make_unique<
			t_btree_2__0_1__3>();
	souffle::RelationWrapper<0, t_btree_2__0_1__3, Tuple<RamDomain, 2>, 2> wrapper_rel_1_assign;
// -- Table: flow
	std::unique_ptr<t_btree_2__0_1> rel_2_flow =
			std::make_unique<t_btree_2__0_1>();
	souffle::RelationWrapper<1, t_btree_2__0_1, Tuple<RamDomain, 2>, 2> wrapper_rel_2_flow;
// -- Table: initLabel
	std::unique_ptr<t_btree_1__0> rel_3_initLabel = std::make_unique<
			t_btree_1__0>();
	souffle::RelationWrapper<2, t_btree_1__0, Tuple<RamDomain, 1>, 1> wrapper_rel_3_initLabel;
// -- Table: initLabelDef
	std::unique_ptr<t_btree_1__0> rel_4_initLabelDef = std::make_unique<
			t_btree_1__0>();
	souffle::RelationWrapper<3, t_btree_1__0, Tuple<RamDomain, 1>, 1> wrapper_rel_4_initLabelDef;
// -- Table: read
	std::unique_ptr<t_btree_2__0_1> rel_5_read =
			std::make_unique<t_btree_2__0_1>();
	souffle::RelationWrapper<4, t_btree_2__0_1, Tuple<RamDomain, 2>, 2> wrapper_rel_5_read;
// -- Table: isVar
	std::unique_ptr<t_btree_1__0> rel_6_isVar =
			std::make_unique<t_btree_1__0>();
	souffle::RelationWrapper<5, t_btree_1__0, Tuple<RamDomain, 1>, 1> wrapper_rel_6_isVar;
// -- Table: rdEntry
	std::unique_ptr<t_btree_3__0_1_2__7> rel_7_rdEntry = std::make_unique<
			t_btree_3__0_1_2__7>();
	souffle::RelationWrapper<6, t_btree_3__0_1_2__7, Tuple<RamDomain, 3>, 3> wrapper_rel_7_rdEntry;
// -- Table: @delta_rdEntry
	std::unique_ptr<t_btree_3__0_1_2> rel_8_delta_rdEntry = std::make_unique<
			t_btree_3__0_1_2>();
// -- Table: @new_rdEntry
	std::unique_ptr<t_btree_3__0_1_2> rel_9_new_rdEntry = std::make_unique<
			t_btree_3__0_1_2>();
// -- Table: rdExit
	std::unique_ptr<t_btree_3__0_1_2__7> rel_10_rdExit = std::make_unique<
			t_btree_3__0_1_2__7>();
	souffle::RelationWrapper<7, t_btree_3__0_1_2__7, Tuple<RamDomain, 3>, 3> wrapper_rel_10_rdExit;
// -- Table: @delta_rdExit
	std::unique_ptr<t_btree_3__0_1_2> rel_11_delta_rdExit = std::make_unique<
			t_btree_3__0_1_2>();
// -- Table: @new_rdExit
	std::unique_ptr<t_btree_3__0_1_2> rel_12_new_rdExit = std::make_unique<
			t_btree_3__0_1_2>();
public:
	Sf_reachingDef() :
			wrapper_rel_1_assign(*rel_1_assign, symTable, "assign",
					std::array<const char *, 2> { { "i:Label", "s:Var" } },
					std::array<const char *, 2> { { "l", "x" } }),

			wrapper_rel_2_flow(*rel_2_flow, symTable, "flow",
					std::array<const char *, 2> { { "i:Label", "i:Label" } },
					std::array<const char *, 2> { { "l1", "l2" } }),

			wrapper_rel_3_initLabel(*rel_3_initLabel, symTable, "initLabel",
					std::array<const char *, 1> { { "i:Label" } },
					std::array<const char *, 1> { { "l" } }),

			wrapper_rel_4_initLabelDef(*rel_4_initLabelDef, symTable,
					"initLabelDef",
					std::array<const char *, 1> { { "i:Label" } },
					std::array<const char *, 1> { { "l" } }),

			wrapper_rel_5_read(*rel_5_read, symTable, "read",
					std::array<const char *, 2> { { "i:Label", "s:Var" } },
					std::array<const char *, 2> { { "l", "x" } }),

			wrapper_rel_6_isVar(*rel_6_isVar, symTable, "isVar",
					std::array<const char *, 1> { { "s:Var" } },
					std::array<const char *, 1> { { "x" } }),

			wrapper_rel_7_rdEntry(*rel_7_rdEntry, symTable, "rdEntry",
					std::array<const char *, 3> { { "i:Label", "s:Var",
							"i:Label" } }, std::array<const char *, 3> { { "l",
							"x", "def" } }),

			wrapper_rel_10_rdExit(*rel_10_rdExit, symTable, "rdExit",
					std::array<const char *, 3> { { "i:Label", "s:Var",
							"i:Label" } }, std::array<const char *, 3> { { "l",
							"x", "def" } }) {
		addRelation("assign", &wrapper_rel_1_assign, true, false);
		addRelation("flow", &wrapper_rel_2_flow, true, false);
		addRelation("initLabel", &wrapper_rel_3_initLabel, true, false);
		addRelation("initLabelDef", &wrapper_rel_4_initLabelDef, false, false);
		addRelation("read", &wrapper_rel_5_read, true, false);
		addRelation("isVar", &wrapper_rel_6_isVar, false, false);
		addRelation("rdEntry", &wrapper_rel_7_rdEntry, false, true);
		addRelation("rdExit", &wrapper_rel_10_rdExit, false, true);
	}
	~Sf_reachingDef() {
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
				try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","../tests/test1/assign.facts"}, {"name","assign"}});
					if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
					IODirectives ioDirectives(directiveMap);
					IOSystem::getInstance().getReader(SymbolMask( {0, 1}), symTable, ioDirectives, 0)->readAll(*rel_1_assign);
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
				try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","../tests/test1/flow.facts"}, {"name","flow"}});
					if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
					IODirectives ioDirectives(directiveMap);
					IOSystem::getInstance().getReader(SymbolMask( {0, 0}), symTable, ioDirectives, 0)->readAll(*rel_2_flow);
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
				try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","../tests/test1/initLabel.facts"}, {"name","initLabel"}});
					if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
					IODirectives ioDirectives(directiveMap);
					IOSystem::getInstance().getReader(SymbolMask( {0}), symTable, ioDirectives, 0)->readAll(*rel_3_initLabel);
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
			/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
			SignalHandler::instance()->setMsg(R"_(initLabelDef(999).
in file /home/gq/Programming/souffle/src/dataflowTest/rd/reachingDef.dl [8:1-8:19])_");
			/* BEGIN visitFact @Synthesiser.cpp:239 */
			rel_4_initLabelDef->insert(/* BEGIN visitNumber @Synthesiser.cpp:1194 */
					RamDomain(999)/* END visitNumber @Synthesiser.cpp:1196 */
			);
			/* END visitFact @Synthesiser.cpp:242 */
			/* END visitDebugInfo @Synthesiser.cpp:611 */
			/* END visitSequence @Synthesiser.cpp:504 */
		}();
		/* END STRATUM 3 */
		/* BEGIN STRATUM 4 */
		[&]() {
			/* BEGIN visitSequence @Synthesiser.cpp:500 */
			/* BEGIN visitCreate @Synthesiser.cpp:234 */
			/* END visitCreate @Synthesiser.cpp:235 */
			/* BEGIN visitLoad @Synthesiser.cpp:246 */
			if (performIO) {
				try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"filename","../tests/test1/read.facts"}, {"name","read"}});
					if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
					IODirectives ioDirectives(directiveMap);
					IOSystem::getInstance().getReader(SymbolMask( {0, 1}), symTable, ioDirectives, 0)->readAll(*rel_5_read);
				} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
			}
			/* END visitLoad @Synthesiser.cpp:273 */
			/* END visitSequence @Synthesiser.cpp:504 */
		}();
		/* END STRATUM 4 */
		/* BEGIN STRATUM 5 */
		[&]() {
			/* BEGIN visitSequence @Synthesiser.cpp:500 */
			/* BEGIN visitCreate @Synthesiser.cpp:234 */
			/* END visitCreate @Synthesiser.cpp:235 */
			/* BEGIN visitSequence @Synthesiser.cpp:500 */
			/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
			SignalHandler::instance()->setMsg(R"_(isVar(x) :- 
   assign(_,x).
in file /home/gq/Programming/souffle/src/dataflowTest/rd/reachingDef.dl [12:1-12:26])_");
			/* BEGIN visitInsert @Synthesiser.cpp:306 */
			if (!rel_1_assign->empty()) [&]() {
				auto part = rel_1_assign->partition();
				PARALLEL_START;
				CREATE_OP_CONTEXT(rel_1_assign_op_ctxt,rel_1_assign->createContext());
				CREATE_OP_CONTEXT(rel_6_isVar_op_ctxt,rel_6_isVar->createContext());
				/* BEGIN visitScan @Synthesiser.cpp:640 */
				pfor(auto it = part.begin(); it<part.end();++it) {
					try {for(const auto& env0 : *it) {
							/* BEGIN visitSearch @Synthesiser.cpp:634 */
							/* BEGIN visitProject @Synthesiser.cpp:961 */
							Tuple<RamDomain,1> tuple( { {static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
													env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
											)}});
							rel_6_isVar->insert(tuple,READ_OP_CONTEXT(rel_6_isVar_op_ctxt));
							/* END visitProject @Synthesiser.cpp:981 */
							/* END visitSearch @Synthesiser.cpp:636 */
						}
					} catch(std::exception &e) {SignalHandler::instance()->error(e.what());}
				}
				/* END visitScan @Synthesiser.cpp:694 */
				PARALLEL_END;
			}
			();/* END visitInsert @Synthesiser.cpp:443 */
			/* END visitDebugInfo @Synthesiser.cpp:611 */
			/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
			SignalHandler::instance()->setMsg(R"_(isVar(x) :- 
   read(_,x).
in file /home/gq/Programming/souffle/src/dataflowTest/rd/reachingDef.dl [13:1-13:24])_");
			/* BEGIN visitInsert @Synthesiser.cpp:306 */
			if (!rel_5_read->empty()) [&]() {
				auto part = rel_5_read->partition();
				PARALLEL_START;
				CREATE_OP_CONTEXT(rel_6_isVar_op_ctxt,rel_6_isVar->createContext());
				CREATE_OP_CONTEXT(rel_5_read_op_ctxt,rel_5_read->createContext());
				/* BEGIN visitScan @Synthesiser.cpp:640 */
				pfor(auto it = part.begin(); it<part.end();++it) {
					try {for(const auto& env0 : *it) {
							/* BEGIN visitSearch @Synthesiser.cpp:634 */
							/* BEGIN visitProject @Synthesiser.cpp:961 */
							Tuple<RamDomain,1> tuple( { {static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
													env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
											)}});
							rel_6_isVar->insert(tuple,READ_OP_CONTEXT(rel_6_isVar_op_ctxt));
							/* END visitProject @Synthesiser.cpp:981 */
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
			/* BEGIN visitDrop @Synthesiser.cpp:478 */
			if (!isHintsProfilingEnabled() && (performIO || 0)) rel_5_read->purge();
			/* END visitDrop @Synthesiser.cpp:485 */
			/* END visitSequence @Synthesiser.cpp:504 */
		}();
		/* END STRATUM 5 */
		/* BEGIN STRATUM 6 */
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
			/* BEGIN visitSequence @Synthesiser.cpp:500 */
			/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
			SignalHandler::instance()->setMsg(R"_(rdEntry(l,x,def) :- 
   initLabel(l),
   isVar(x),
   initLabelDef(def).
in file /home/gq/Programming/souffle/src/dataflowTest/rd/reachingDef.dl [22:1-22:63])_");
			/* BEGIN visitInsert @Synthesiser.cpp:306 */
			if (!rel_3_initLabel->empty()&&!rel_4_initLabelDef->empty()&&!rel_6_isVar->empty()) [&]() {
				auto part = rel_3_initLabel->partition();
				PARALLEL_START;
				CREATE_OP_CONTEXT(rel_3_initLabel_op_ctxt,rel_3_initLabel->createContext());
				CREATE_OP_CONTEXT(rel_4_initLabelDef_op_ctxt,rel_4_initLabelDef->createContext());
				CREATE_OP_CONTEXT(rel_6_isVar_op_ctxt,rel_6_isVar->createContext());
				CREATE_OP_CONTEXT(rel_7_rdEntry_op_ctxt,rel_7_rdEntry->createContext());
				/* BEGIN visitScan @Synthesiser.cpp:640 */
				pfor(auto it = part.begin(); it<part.end();++it) {
					try {for(const auto& env0 : *it) {
							/* BEGIN visitSearch @Synthesiser.cpp:634 */
							/* BEGIN visitScan @Synthesiser.cpp:640 */
							for(const auto& env1 : *rel_6_isVar) {
								/* BEGIN visitSearch @Synthesiser.cpp:634 */
								/* BEGIN visitScan @Synthesiser.cpp:640 */
								for(const auto& env2 : *rel_4_initLabelDef) {
									/* BEGIN visitSearch @Synthesiser.cpp:634 */
									/* BEGIN visitProject @Synthesiser.cpp:961 */
									Tuple<RamDomain,3> tuple( { {static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
															env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
													),static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
															env1[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
													),static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
															env2[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
													)}});
									rel_7_rdEntry->insert(tuple,READ_OP_CONTEXT(rel_7_rdEntry_op_ctxt));
									/* END visitProject @Synthesiser.cpp:981 */
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
			}
			();/* END visitInsert @Synthesiser.cpp:443 */
			/* END visitDebugInfo @Synthesiser.cpp:611 */
			/* BEGIN visitMerge @Synthesiser.cpp:447 */
			rel_8_delta_rdEntry->insertAll(*rel_7_rdEntry);
			/* END visitMerge @Synthesiser.cpp:459 */
			/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
			SignalHandler::instance()->setMsg(R"_(rdExit(l,x,l) :- 
   assign(l,x).
in file /home/gq/Programming/souffle/src/dataflowTest/rd/reachingDef.dl [27:1-27:30])_");
			/* BEGIN visitInsert @Synthesiser.cpp:306 */
			if (!rel_1_assign->empty()) [&]() {
				auto part = rel_1_assign->partition();
				PARALLEL_START;
				CREATE_OP_CONTEXT(rel_1_assign_op_ctxt,rel_1_assign->createContext());
				CREATE_OP_CONTEXT(rel_10_rdExit_op_ctxt,rel_10_rdExit->createContext());
				/* BEGIN visitScan @Synthesiser.cpp:640 */
				pfor(auto it = part.begin(); it<part.end();++it) {
					try {for(const auto& env0 : *it) {
							/* BEGIN visitSearch @Synthesiser.cpp:634 */
							/* BEGIN visitProject @Synthesiser.cpp:961 */
							Tuple<RamDomain,3> tuple( { {static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
													env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
											),static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
													env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
											),static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
													env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
											)}});
							rel_10_rdExit->insert(tuple,READ_OP_CONTEXT(rel_10_rdExit_op_ctxt));
							/* END visitProject @Synthesiser.cpp:981 */
							/* END visitSearch @Synthesiser.cpp:636 */
						}
					} catch(std::exception &e) {SignalHandler::instance()->error(e.what());}
				}
				/* END visitScan @Synthesiser.cpp:694 */
				PARALLEL_END;
			}
			();/* END visitInsert @Synthesiser.cpp:443 */
			/* END visitDebugInfo @Synthesiser.cpp:611 */
			/* BEGIN visitMerge @Synthesiser.cpp:447 */
			rel_11_delta_rdExit->insertAll(*rel_10_rdExit);
			/* END visitMerge @Synthesiser.cpp:459 */
			/* BEGIN visitLoop @Synthesiser.cpp:543 */
			iter = 0;
			for(;;) {
				/* BEGIN visitSequence @Synthesiser.cpp:500 */
				/* BEGIN visitParallel @Synthesiser.cpp:509 */
				SECTIONS_START;
				SECTION_START;
				/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
				SignalHandler::instance()->setMsg(R"_(rdEntry(l2,x,def) :- 
   rdExit(l1,x,def),
   flow(l1,l2).
in file /home/gq/Programming/souffle/src/dataflowTest/rd/reachingDef.dl [24:1-24:52])_");
				/* BEGIN visitInsert @Synthesiser.cpp:306 */
				if (!rel_11_delta_rdExit->empty()&&!rel_2_flow->empty()) [&]() {
					auto part = rel_11_delta_rdExit->partition();
					PARALLEL_START;
					CREATE_OP_CONTEXT(rel_11_delta_rdExit_op_ctxt,rel_11_delta_rdExit->createContext());
					CREATE_OP_CONTEXT(rel_9_new_rdEntry_op_ctxt,rel_9_new_rdEntry->createContext());
					CREATE_OP_CONTEXT(rel_2_flow_op_ctxt,rel_2_flow->createContext());
					CREATE_OP_CONTEXT(rel_7_rdEntry_op_ctxt,rel_7_rdEntry->createContext());
					/* BEGIN visitScan @Synthesiser.cpp:640 */
					pfor(auto it = part.begin(); it<part.end();++it) {
						try {for(const auto& env0 : *it) {
								/* BEGIN visitSearch @Synthesiser.cpp:634 */
								/* BEGIN visitScan @Synthesiser.cpp:640 */
								for(const auto& env1 : *rel_2_flow) {
									/* BEGIN visitSearch @Synthesiser.cpp:634 */
									/* BEGIN visitFilter @Synthesiser.cpp:950 */
									if( /* BEGIN visitNegation @Synthesiser.cpp:998 */
											!(/* BEGIN visitExistenceCheck @Synthesiser.cpp:1103 */
													rel_7_rdEntry->contains(Tuple<RamDomain,3>( { {/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																			env1[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
																			,/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																			env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
																			,/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																			env0[2]/* END visitElementAccess @Synthesiser.cpp:1204 */
																		}}),READ_OP_CONTEXT(rel_7_rdEntry_op_ctxt))/* END visitExistenceCheck @Synthesiser.cpp:1124 */
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
											Tuple<RamDomain,3> tuple( { {static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																	env1[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
															),static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																	env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
															),static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																	env0[2]/* END visitElementAccess @Synthesiser.cpp:1204 */
															)}});
											rel_9_new_rdEntry->insert(tuple,READ_OP_CONTEXT(rel_9_new_rdEntry_op_ctxt));
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
				/* BEGIN visitDebugInfo @Synthesiser.cpp:604 */
				SignalHandler::instance()->setMsg(R"_(rdExit(l,x,def) :- 
   rdEntry(l,x,def),
   !assign(l,x).
in file /home/gq/Programming/souffle/src/dataflowTest/rd/reachingDef.dl [29:1-29:51])_");
				/* BEGIN visitInsert @Synthesiser.cpp:306 */
				if (!rel_8_delta_rdEntry->empty()) [&]() {
					auto part = rel_8_delta_rdEntry->partition();
					PARALLEL_START;
					CREATE_OP_CONTEXT(rel_8_delta_rdEntry_op_ctxt,rel_8_delta_rdEntry->createContext());
					CREATE_OP_CONTEXT(rel_12_new_rdExit_op_ctxt,rel_12_new_rdExit->createContext());
					CREATE_OP_CONTEXT(rel_1_assign_op_ctxt,rel_1_assign->createContext());
					CREATE_OP_CONTEXT(rel_10_rdExit_op_ctxt,rel_10_rdExit->createContext());
					/* BEGIN visitScan @Synthesiser.cpp:640 */
					pfor(auto it = part.begin(); it<part.end();++it) {
						try {for(const auto& env0 : *it) {
								/* BEGIN visitSearch @Synthesiser.cpp:634 */
								/* BEGIN visitFilter @Synthesiser.cpp:950 */
								if( /* BEGIN visitNegation @Synthesiser.cpp:998 */
										!(/* BEGIN visitExistenceCheck @Synthesiser.cpp:1103 */
												rel_10_rdExit->contains(Tuple<RamDomain,3>( { {/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																		env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
																		,/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																		env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
																		,/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																		env0[2]/* END visitElementAccess @Synthesiser.cpp:1204 */
																	}}),READ_OP_CONTEXT(rel_10_rdExit_op_ctxt))/* END visitExistenceCheck @Synthesiser.cpp:1124 */
										)/* END visitNegation @Synthesiser.cpp:1002 */
								) {
									/* BEGIN visitFilter @Synthesiser.cpp:950 */
									if( /* BEGIN visitNegation @Synthesiser.cpp:998 */
											!(/* BEGIN visitExistenceCheck @Synthesiser.cpp:1103 */
													rel_1_assign->contains(Tuple<RamDomain,2>( { {/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																			env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
																			,/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																			env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
																		}}),READ_OP_CONTEXT(rel_1_assign_op_ctxt))/* END visitExistenceCheck @Synthesiser.cpp:1124 */
											)/* END visitNegation @Synthesiser.cpp:1002 */
									) {
										/* BEGIN visitProject @Synthesiser.cpp:961 */
										Tuple<RamDomain,3> tuple( { {static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																env0[0]/* END visitElementAccess @Synthesiser.cpp:1204 */
														),static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																env0[1]/* END visitElementAccess @Synthesiser.cpp:1204 */
														),static_cast<RamDomain>(/* BEGIN visitElementAccess @Synthesiser.cpp:1201 */
																env0[2]/* END visitElementAccess @Synthesiser.cpp:1204 */
														)}});
										rel_12_new_rdExit->insert(tuple,READ_OP_CONTEXT(rel_12_new_rdExit_op_ctxt));
										/* END visitProject @Synthesiser.cpp:981 */
									}
									/* END visitFilter @Synthesiser.cpp:956 */
								}
								/* END visitFilter @Synthesiser.cpp:956 */
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
				SECTIONS_END;
				/* END visitParallel @Synthesiser.cpp:539 */
				/* BEGIN visitExit @Synthesiser.cpp:566 */
				if(/* BEGIN visitConjunction @Synthesiser.cpp:988 */
						((/* BEGIN visitEmptinessCheck @Synthesiser.cpp:1095 */
										rel_9_new_rdEntry->empty()/* END visitEmptinessCheck @Synthesiser.cpp:1098 */
								) && (/* BEGIN visitEmptinessCheck @Synthesiser.cpp:1095 */
										rel_12_new_rdExit->empty()/* END visitEmptinessCheck @Synthesiser.cpp:1098 */
								))/* END visitConjunction @Synthesiser.cpp:994 */
				) break;
				/* END visitExit @Synthesiser.cpp:570 */
				/* BEGIN visitSequence @Synthesiser.cpp:500 */
				/* BEGIN visitSequence @Synthesiser.cpp:500 */
				/* BEGIN visitMerge @Synthesiser.cpp:447 */
				rel_7_rdEntry->insertAll(*rel_9_new_rdEntry);
				/* END visitMerge @Synthesiser.cpp:459 */
				/* BEGIN visitSwap @Synthesiser.cpp:554 */
				std::swap(rel_8_delta_rdEntry, rel_9_new_rdEntry);
				/* END visitSwap @Synthesiser.cpp:562 */
				/* BEGIN visitClear @Synthesiser.cpp:471 */
				rel_9_new_rdEntry->purge();
				/* END visitClear @Synthesiser.cpp:474 */
				/* END visitSequence @Synthesiser.cpp:504 */
				/* BEGIN visitSequence @Synthesiser.cpp:500 */
				/* BEGIN visitMerge @Synthesiser.cpp:447 */
				rel_10_rdExit->insertAll(*rel_12_new_rdExit);
				/* END visitMerge @Synthesiser.cpp:459 */
				/* BEGIN visitSwap @Synthesiser.cpp:554 */
				std::swap(rel_11_delta_rdExit, rel_12_new_rdExit);
				/* END visitSwap @Synthesiser.cpp:562 */
				/* BEGIN visitClear @Synthesiser.cpp:471 */
				rel_12_new_rdExit->purge();
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
			if (!isHintsProfilingEnabled() && (performIO || 1)) rel_8_delta_rdEntry->purge();
			/* END visitDrop @Synthesiser.cpp:485 */
			/* BEGIN visitDrop @Synthesiser.cpp:478 */
			if (!isHintsProfilingEnabled() && (performIO || 1)) rel_9_new_rdEntry->purge();
			/* END visitDrop @Synthesiser.cpp:485 */
			/* BEGIN visitSequence @Synthesiser.cpp:500 */
			/* BEGIN visitDrop @Synthesiser.cpp:478 */
			if (!isHintsProfilingEnabled() && (performIO || 1)) rel_11_delta_rdExit->purge();
			/* END visitDrop @Synthesiser.cpp:485 */
			/* BEGIN visitDrop @Synthesiser.cpp:478 */
			if (!isHintsProfilingEnabled() && (performIO || 1)) rel_12_new_rdExit->purge();
			/* END visitDrop @Synthesiser.cpp:485 */
			/* END visitSequence @Synthesiser.cpp:504 */
			/* END visitSequence @Synthesiser.cpp:504 */
			/* END visitSequence @Synthesiser.cpp:504 */
			/* BEGIN visitStore @Synthesiser.cpp:277 */
			if (performIO) {
				try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"attributeNames","l\tx\tdef"}, {"filename","test1/rdEntry.csv"}, {"name","rdEntry"}});
					if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
					IODirectives ioDirectives(directiveMap);
					IOSystem::getInstance().getWriter(SymbolMask( {0, 1, 0}), symTable, ioDirectives, 0)->writeAll(*rel_7_rdEntry);
				} catch (std::exception& e) {std::cerr << e.what();exit(1);}
			}
			/* END visitStore @Synthesiser.cpp:302 */
			/* BEGIN visitStore @Synthesiser.cpp:277 */
			if (performIO) {
				try {std::map<std::string, std::string> directiveMap( { {"IO","file"}, {"attributeNames","l\tx\tdef"}, {"filename","test1/rdExit.csv"}, {"name","rdExit"}});
					if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
					IODirectives ioDirectives(directiveMap);
					IOSystem::getInstance().getWriter(SymbolMask( {0, 1, 0}), symTable, ioDirectives, 0)->writeAll(*rel_10_rdExit);
				} catch (std::exception& e) {std::cerr << e.what();exit(1);}
			}
			/* END visitStore @Synthesiser.cpp:302 */
			/* BEGIN visitDrop @Synthesiser.cpp:478 */
			if (!isHintsProfilingEnabled() && (performIO || 0)) rel_3_initLabel->purge();
			/* END visitDrop @Synthesiser.cpp:485 */
			/* BEGIN visitDrop @Synthesiser.cpp:478 */
			if (!isHintsProfilingEnabled() && (performIO || 0)) rel_2_flow->purge();
			/* END visitDrop @Synthesiser.cpp:485 */
			/* BEGIN visitDrop @Synthesiser.cpp:478 */
			if (!isHintsProfilingEnabled() && (performIO || 0)) rel_1_assign->purge();
			/* END visitDrop @Synthesiser.cpp:485 */
			/* BEGIN visitDrop @Synthesiser.cpp:478 */
			if (!isHintsProfilingEnabled() && (performIO || 0)) rel_4_initLabelDef->purge();
			/* END visitDrop @Synthesiser.cpp:485 */
			/* BEGIN visitDrop @Synthesiser.cpp:478 */
			if (!isHintsProfilingEnabled() && (performIO || 0)) rel_6_isVar->purge();
			/* END visitDrop @Synthesiser.cpp:485 */
			/* BEGIN visitDrop @Synthesiser.cpp:478 */
			if (!isHintsProfilingEnabled() && (performIO || 0)) rel_7_rdEntry->purge();
			/* END visitDrop @Synthesiser.cpp:485 */
			/* BEGIN visitDrop @Synthesiser.cpp:478 */
			if (!isHintsProfilingEnabled() && (performIO || 0)) rel_10_rdExit->purge();
			/* END visitDrop @Synthesiser.cpp:485 */
			/* END visitSequence @Synthesiser.cpp:504 */
		}();
		/* END STRATUM 6 */

// -- relation hint statistics --
		if (isHintsProfilingEnabled()) {
			std::cout << " -- Operation Hint Statistics --\n";
			std::cout << "Relation rel_1_assign:\n";
			rel_1_assign->printHintStatistics(std::cout, "  ");
			std::cout << "\n";
			std::cout << "Relation rel_2_flow:\n";
			rel_2_flow->printHintStatistics(std::cout, "  ");
			std::cout << "\n";
			std::cout << "Relation rel_3_initLabel:\n";
			rel_3_initLabel->printHintStatistics(std::cout, "  ");
			std::cout << "\n";
			std::cout << "Relation rel_4_initLabelDef:\n";
			rel_4_initLabelDef->printHintStatistics(std::cout, "  ");
			std::cout << "\n";
			std::cout << "Relation rel_5_read:\n";
			rel_5_read->printHintStatistics(std::cout, "  ");
			std::cout << "\n";
			std::cout << "Relation rel_6_isVar:\n";
			rel_6_isVar->printHintStatistics(std::cout, "  ");
			std::cout << "\n";
			std::cout << "Relation rel_7_rdEntry:\n";
			rel_7_rdEntry->printHintStatistics(std::cout, "  ");
			std::cout << "\n";
			std::cout << "Relation rel_8_delta_rdEntry:\n";
			rel_8_delta_rdEntry->printHintStatistics(std::cout, "  ");
			std::cout << "\n";
			std::cout << "Relation rel_9_new_rdEntry:\n";
			rel_9_new_rdEntry->printHintStatistics(std::cout, "  ");
			std::cout << "\n";
			std::cout << "Relation rel_10_rdExit:\n";
			rel_10_rdExit->printHintStatistics(std::cout, "  ");
			std::cout << "\n";
			std::cout << "Relation rel_11_delta_rdExit:\n";
			rel_11_delta_rdExit->printHintStatistics(std::cout, "  ");
			std::cout << "\n";
			std::cout << "Relation rel_12_new_rdExit:\n";
			rel_12_new_rdExit->printHintStatistics(std::cout, "  ");
			std::cout << "\n";
		}
		SignalHandler::instance()->reset();
	}
public:
	void run(size_t stratumIndex = (size_t) -1) override {
		runFunction(".", ".", stratumIndex, false);
	}
public:
	void runAll(std::string inputDirectory = ".", std::string outputDirectory =
			".", size_t stratumIndex = (size_t) -1) override {
		runFunction(inputDirectory, outputDirectory, stratumIndex, true);
	}
public:
	void printAll(std::string outputDirectory = ".") override {
		try {
			std::map < std::string, std::string > directiveMap( {
					{ "IO", "file" }, { "attributeNames", "l\tx\tdef" }, {
							"filename", "test1/rdEntry.csv" }, { "name",
							"rdEntry" } });
			if (!outputDirectory.empty() && directiveMap["IO"] == "file"
					&& directiveMap["filename"].front() != '/') {
				directiveMap["filename"] = outputDirectory + "/"
						+ directiveMap["filename"];
			}
			IODirectives ioDirectives(directiveMap);
			IOSystem::getInstance().getWriter(SymbolMask( { 0, 1, 0 }),
					symTable, ioDirectives, 0)->writeAll(*rel_7_rdEntry);
		} catch (std::exception& e) {
			std::cerr << e.what();
			exit(1);
		}
		try {
			std::map < std::string, std::string > directiveMap( {
					{ "IO", "file" }, { "attributeNames", "l\tx\tdef" }, {
							"filename", "test1/rdExit.csv" },
					{ "name", "rdExit" } });
			if (!outputDirectory.empty() && directiveMap["IO"] == "file"
					&& directiveMap["filename"].front() != '/') {
				directiveMap["filename"] = outputDirectory + "/"
						+ directiveMap["filename"];
			}
			IODirectives ioDirectives(directiveMap);
			IOSystem::getInstance().getWriter(SymbolMask( { 0, 1, 0 }),
					symTable, ioDirectives, 0)->writeAll(*rel_10_rdExit);
		} catch (std::exception& e) {
			std::cerr << e.what();
			exit(1);
		}
	}
public:
	void loadAll(std::string inputDirectory = ".") override {
		try {
			std::map < std::string, std::string > directiveMap( {
					{ "IO", "file" }, { "filename",
							"../tests/test1/assign.facts" },
					{ "name", "assign" } });
			if (!inputDirectory.empty() && directiveMap["IO"] == "file"
					&& directiveMap["filename"].front() != '/') {
				directiveMap["filename"] = inputDirectory + "/"
						+ directiveMap["filename"];
			}
			IODirectives ioDirectives(directiveMap);
			IOSystem::getInstance().getReader(SymbolMask( { 0, 1 }), symTable,
					ioDirectives, 0)->readAll(*rel_1_assign);
		} catch (std::exception& e) {
			std::cerr << "Error loading data: " << e.what() << '\n';
		}
		try {
			std::map < std::string, std::string > directiveMap( {
					{ "IO", "file" },
					{ "filename", "../tests/test1/flow.facts" }, { "name",
							"flow" } });
			if (!inputDirectory.empty() && directiveMap["IO"] == "file"
					&& directiveMap["filename"].front() != '/') {
				directiveMap["filename"] = inputDirectory + "/"
						+ directiveMap["filename"];
			}
			IODirectives ioDirectives(directiveMap);
			IOSystem::getInstance().getReader(SymbolMask( { 0, 0 }), symTable,
					ioDirectives, 0)->readAll(*rel_2_flow);
		} catch (std::exception& e) {
			std::cerr << "Error loading data: " << e.what() << '\n';
		}
		try {
			std::map < std::string, std::string > directiveMap( {
					{ "IO", "file" }, { "filename",
							"../tests/test1/initLabel.facts" }, { "name",
							"initLabel" } });
			if (!inputDirectory.empty() && directiveMap["IO"] == "file"
					&& directiveMap["filename"].front() != '/') {
				directiveMap["filename"] = inputDirectory + "/"
						+ directiveMap["filename"];
			}
			IODirectives ioDirectives(directiveMap);
			IOSystem::getInstance().getReader(SymbolMask( { 0 }), symTable,
					ioDirectives, 0)->readAll(*rel_3_initLabel);
		} catch (std::exception& e) {
			std::cerr << "Error loading data: " << e.what() << '\n';
		}
		try {
			std::map < std::string, std::string > directiveMap( {
					{ "IO", "file" },
					{ "filename", "../tests/test1/read.facts" }, { "name",
							"read" } });
			if (!inputDirectory.empty() && directiveMap["IO"] == "file"
					&& directiveMap["filename"].front() != '/') {
				directiveMap["filename"] = inputDirectory + "/"
						+ directiveMap["filename"];
			}
			IODirectives ioDirectives(directiveMap);
			IOSystem::getInstance().getReader(SymbolMask( { 0, 1 }), symTable,
					ioDirectives, 0)->readAll(*rel_5_read);
		} catch (std::exception& e) {
			std::cerr << "Error loading data: " << e.what() << '\n';
		}
	}
public:
	void dumpInputs(std::ostream& out = std::cout) override {
		try {
			IODirectives ioDirectives;
			ioDirectives.setIOType("stdout");
			ioDirectives.setRelationName("rel_1_assign");
			IOSystem::getInstance().getWriter(SymbolMask( { 0, 1 }), symTable,
					ioDirectives, 0)->writeAll(*rel_1_assign);
		} catch (std::exception& e) {
			std::cerr << e.what();
			exit(1);
		}
		try {
			IODirectives ioDirectives;
			ioDirectives.setIOType("stdout");
			ioDirectives.setRelationName("rel_2_flow");
			IOSystem::getInstance().getWriter(SymbolMask( { 0, 0 }), symTable,
					ioDirectives, 0)->writeAll(*rel_2_flow);
		} catch (std::exception& e) {
			std::cerr << e.what();
			exit(1);
		}
		try {
			IODirectives ioDirectives;
			ioDirectives.setIOType("stdout");
			ioDirectives.setRelationName("rel_3_initLabel");
			IOSystem::getInstance().getWriter(SymbolMask( { 0 }), symTable,
					ioDirectives, 0)->writeAll(*rel_3_initLabel);
		} catch (std::exception& e) {
			std::cerr << e.what();
			exit(1);
		}
		try {
			IODirectives ioDirectives;
			ioDirectives.setIOType("stdout");
			ioDirectives.setRelationName("rel_5_read");
			IOSystem::getInstance().getWriter(SymbolMask( { 0, 1 }), symTable,
					ioDirectives, 0)->writeAll(*rel_5_read);
		} catch (std::exception& e) {
			std::cerr << e.what();
			exit(1);
		}
	}
public:
	void dumpOutputs(std::ostream& out = std::cout) override {
		try {
			IODirectives ioDirectives;
			ioDirectives.setIOType("stdout");
			ioDirectives.setRelationName("rel_7_rdEntry");
			IOSystem::getInstance().getWriter(SymbolMask( { 0, 1, 0 }),
					symTable, ioDirectives, 0)->writeAll(*rel_7_rdEntry);
		} catch (std::exception& e) {
			std::cerr << e.what();
			exit(1);
		}
		try {
			IODirectives ioDirectives;
			ioDirectives.setIOType("stdout");
			ioDirectives.setRelationName("rel_10_rdExit");
			IOSystem::getInstance().getWriter(SymbolMask( { 0, 1, 0 }),
					symTable, ioDirectives, 0)->writeAll(*rel_10_rdExit);
		} catch (std::exception& e) {
			std::cerr << e.what();
			exit(1);
		}
	}
public:
	const SymbolTable &getSymbolTable() const override {
		return symTable;
	}
};
SouffleProgram *newInstance_reachingDef() {
	return new Sf_reachingDef;
}
SymbolTable *getST_reachingDef(SouffleProgram *p) {
	return &reinterpret_cast<Sf_reachingDef*>(p)->symTable;
}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_reachingDef: public souffle::ProgramFactory {
	SouffleProgram *newInstance() {
		return new Sf_reachingDef();
	};
public:
	factory_Sf_reachingDef() : ProgramFactory("reachingDef") {}
};
static factory_Sf_reachingDef __factory_Sf_reachingDef_instance;
}
#else
}
int main(int argc, char** argv) {
try {
souffle::CmdOptions opt(R"(reachingDef.dl)", R"(.)", R"(.)", false, R"()", 1,
		-1);
if (!opt.parse(argc, argv))
	return 1;
#if defined(_OPENMP) 
omp_set_nested(true);

#endif
souffle::Sf_reachingDef obj;
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(),
		opt.getStratumIndex());
return 0;
} catch (std::exception &e) {
souffle::SignalHandler::instance()->error(e.what());
}
}

#endif
