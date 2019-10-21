// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hh"

// User implementation prologue.

#line 51 "parser.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 85 "./parser.yy" // lalr1.cc:413

    #include "ParserDriver.h"

#line 57 "parser.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 143 "parser.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (ParserDriver &driver_yyarg, yyscan_t yyscanner_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg),
      yyscanner (yyscanner_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 115: // arg
        value.move< AstArgument * > (that.value);
        break;

      case 120: // non_empty_arg_list
      case 121: // arg_list
      case 122: // atom
        value.move< AstAtom * > (that.value);
        break;

      case 124: // fact
        value.move< AstClause * > (that.value);
        break;

      case 139: // component_head
      case 140: // component_body
      case 141: // component
        value.move< AstComponent * > (that.value);
        break;

      case 142: // comp_init
        value.move< AstComponentInit * > (that.value);
        break;

      case 138: // comp_type
        value.move< AstComponentType * > (that.value);
        break;

      case 6: // "number"
        value.move< AstDomain > (that.value);
        break;

      case 94: // enumtype
        value.move< AstEnumType * > (that.value);
        break;

      case 130: // exec_order_list
      case 131: // exec_order
        value.move< AstExecutionOrder * > (that.value);
        break;

      case 132: // exec_plan_list
      case 133: // exec_plan
        value.move< AstExecutionPlan * > (that.value);
        break;

      case 99: // functor_decl
        value.move< AstFunctorDeclaration * > (that.value);
        break;

      case 109: // non_empty_key_value_pairs
      case 110: // key_value_pairs
      case 114: // iodirective_body
        value.move< AstIO * > (that.value);
        break;

      case 106: // lattice_asscoiation
        value.move< AstLatticeAssociation * > (that.value);
        break;

      case 107: // lattice_def
      case 108: // lattice_def_type
        value.move< AstLatticeBinaryFunction * > (that.value);
        break;

      case 89: // pragma
        value.move< AstPragma * > (that.value);
        break;

      case 116: // condition
        value.move< AstQuestionMark * > (that.value);
        break;

      case 119: // recordlist
        value.move< AstRecordInit * > (that.value);
        break;

      case 92: // recordtype
        value.move< AstRecordType * > (that.value);
        break;

      case 96: // non_empty_attributes
      case 97: // attributes
      case 104: // relation_body
        value.move< AstRelation * > (that.value);
        break;

      case 95: // rel_id
        value.move< AstRelationIdentifier * > (that.value);
        break;

      case 91: // type
        value.move< AstType * > (that.value);
        break;

      case 90: // type_id
        value.move< AstTypeIdentifier * > (that.value);
        break;

      case 93: // uniontype
        value.move< AstUnionType * > (that.value);
        break;

      case 117: // functor_list
      case 118: // functor_args
        value.move< AstUserDefinedFunctor * > (that.value);
        break;

      case 123: // literal
      case 126: // term
      case 127: // conjunction
      case 128: // disjunction
      case 129: // body
        value.move< RuleBody * > (that.value);
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 100: // functor_type
      case 101: // functor_typeargs
      case 143: // comp_override
        value.move< std::string > (that.value);
        break;

      case 125: // head
        value.move< std::vector<AstAtom*> > (that.value);
        break;

      case 134: // rule_def
      case 135: // rule
        value.move< std::vector<AstClause*> > (that.value);
        break;

      case 113: // iodirective_list
        value.move< std::vector<AstIO *> > (that.value);
        break;

      case 111: // load_head
        value.move< std::vector<AstLoad *> > (that.value);
        break;

      case 102: // relation_decl
      case 103: // relation_list
      case 105: // lattice_decl
        value.move< std::vector<AstRelation *> > (that.value);
        break;

      case 112: // store_head
        value.move< std::vector<AstStore *> > (that.value);
        break;

      case 136: // type_param_list
      case 137: // type_params
        value.move< std::vector<AstTypeIdentifier> > (that.value);
        break;

      case 98: // qualifiers
        value.move< uint32_t > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 115: // arg
        value.copy< AstArgument * > (that.value);
        break;

      case 120: // non_empty_arg_list
      case 121: // arg_list
      case 122: // atom
        value.copy< AstAtom * > (that.value);
        break;

      case 124: // fact
        value.copy< AstClause * > (that.value);
        break;

      case 139: // component_head
      case 140: // component_body
      case 141: // component
        value.copy< AstComponent * > (that.value);
        break;

      case 142: // comp_init
        value.copy< AstComponentInit * > (that.value);
        break;

      case 138: // comp_type
        value.copy< AstComponentType * > (that.value);
        break;

      case 6: // "number"
        value.copy< AstDomain > (that.value);
        break;

      case 94: // enumtype
        value.copy< AstEnumType * > (that.value);
        break;

      case 130: // exec_order_list
      case 131: // exec_order
        value.copy< AstExecutionOrder * > (that.value);
        break;

      case 132: // exec_plan_list
      case 133: // exec_plan
        value.copy< AstExecutionPlan * > (that.value);
        break;

      case 99: // functor_decl
        value.copy< AstFunctorDeclaration * > (that.value);
        break;

      case 109: // non_empty_key_value_pairs
      case 110: // key_value_pairs
      case 114: // iodirective_body
        value.copy< AstIO * > (that.value);
        break;

      case 106: // lattice_asscoiation
        value.copy< AstLatticeAssociation * > (that.value);
        break;

      case 107: // lattice_def
      case 108: // lattice_def_type
        value.copy< AstLatticeBinaryFunction * > (that.value);
        break;

      case 89: // pragma
        value.copy< AstPragma * > (that.value);
        break;

      case 116: // condition
        value.copy< AstQuestionMark * > (that.value);
        break;

      case 119: // recordlist
        value.copy< AstRecordInit * > (that.value);
        break;

      case 92: // recordtype
        value.copy< AstRecordType * > (that.value);
        break;

      case 96: // non_empty_attributes
      case 97: // attributes
      case 104: // relation_body
        value.copy< AstRelation * > (that.value);
        break;

      case 95: // rel_id
        value.copy< AstRelationIdentifier * > (that.value);
        break;

      case 91: // type
        value.copy< AstType * > (that.value);
        break;

      case 90: // type_id
        value.copy< AstTypeIdentifier * > (that.value);
        break;

      case 93: // uniontype
        value.copy< AstUnionType * > (that.value);
        break;

      case 117: // functor_list
      case 118: // functor_args
        value.copy< AstUserDefinedFunctor * > (that.value);
        break;

      case 123: // literal
      case 126: // term
      case 127: // conjunction
      case 128: // disjunction
      case 129: // body
        value.copy< RuleBody * > (that.value);
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 100: // functor_type
      case 101: // functor_typeargs
      case 143: // comp_override
        value.copy< std::string > (that.value);
        break;

      case 125: // head
        value.copy< std::vector<AstAtom*> > (that.value);
        break;

      case 134: // rule_def
      case 135: // rule
        value.copy< std::vector<AstClause*> > (that.value);
        break;

      case 113: // iodirective_list
        value.copy< std::vector<AstIO *> > (that.value);
        break;

      case 111: // load_head
        value.copy< std::vector<AstLoad *> > (that.value);
        break;

      case 102: // relation_decl
      case 103: // relation_list
      case 105: // lattice_decl
        value.copy< std::vector<AstRelation *> > (that.value);
        break;

      case 112: // store_head
        value.copy< std::vector<AstStore *> > (that.value);
        break;

      case 136: // type_param_list
      case 137: // type_params
        value.copy< std::vector<AstTypeIdentifier> > (that.value);
        break;

      case 98: // qualifiers
        value.copy< uint32_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 3: // "reserved keyword"

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 635 "parser.cc" // lalr1.cc:636
        break;

      case 4: // "symbol"

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 642 "parser.cc" // lalr1.cc:636
        break;

      case 5: // "identifier"

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 649 "parser.cc" // lalr1.cc:636
        break;

      case 6: // "number"

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstDomain > (); }
#line 656 "parser.cc" // lalr1.cc:636
        break;

      case 7: // "relational operator"

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 663 "parser.cc" // lalr1.cc:636
        break;

      case 89: // pragma

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstPragma * > (); }
#line 670 "parser.cc" // lalr1.cc:636
        break;

      case 90: // type_id

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstTypeIdentifier * > (); }
#line 677 "parser.cc" // lalr1.cc:636
        break;

      case 91: // type

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstType * > (); }
#line 684 "parser.cc" // lalr1.cc:636
        break;

      case 92: // recordtype

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRecordType * > (); }
#line 691 "parser.cc" // lalr1.cc:636
        break;

      case 93: // uniontype

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUnionType * > (); }
#line 698 "parser.cc" // lalr1.cc:636
        break;

      case 94: // enumtype

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstEnumType * > (); }
#line 705 "parser.cc" // lalr1.cc:636
        break;

      case 95: // rel_id

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelationIdentifier * > (); }
#line 712 "parser.cc" // lalr1.cc:636
        break;

      case 96: // non_empty_attributes

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 719 "parser.cc" // lalr1.cc:636
        break;

      case 97: // attributes

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 726 "parser.cc" // lalr1.cc:636
        break;

      case 98: // qualifiers

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< uint32_t > (); }
#line 733 "parser.cc" // lalr1.cc:636
        break;

      case 99: // functor_decl

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstFunctorDeclaration * > (); }
#line 740 "parser.cc" // lalr1.cc:636
        break;

      case 100: // functor_type

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 747 "parser.cc" // lalr1.cc:636
        break;

      case 101: // functor_typeargs

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 754 "parser.cc" // lalr1.cc:636
        break;

      case 102: // relation_decl

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 761 "parser.cc" // lalr1.cc:636
        break;

      case 103: // relation_list

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 768 "parser.cc" // lalr1.cc:636
        break;

      case 104: // relation_body

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 775 "parser.cc" // lalr1.cc:636
        break;

      case 105: // lattice_decl

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 782 "parser.cc" // lalr1.cc:636
        break;

      case 106: // lattice_asscoiation

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeAssociation * > (); }
#line 789 "parser.cc" // lalr1.cc:636
        break;

      case 107: // lattice_def

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeBinaryFunction * > (); }
#line 796 "parser.cc" // lalr1.cc:636
        break;

      case 108: // lattice_def_type

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeBinaryFunction * > (); }
#line 803 "parser.cc" // lalr1.cc:636
        break;

      case 109: // non_empty_key_value_pairs

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 810 "parser.cc" // lalr1.cc:636
        break;

      case 110: // key_value_pairs

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 817 "parser.cc" // lalr1.cc:636
        break;

      case 111: // load_head

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstLoad *> > (); }
#line 824 "parser.cc" // lalr1.cc:636
        break;

      case 112: // store_head

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstStore *> > (); }
#line 831 "parser.cc" // lalr1.cc:636
        break;

      case 113: // iodirective_list

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstIO *> > (); }
#line 838 "parser.cc" // lalr1.cc:636
        break;

      case 114: // iodirective_body

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 845 "parser.cc" // lalr1.cc:636
        break;

      case 115: // arg

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstArgument * > (); }
#line 852 "parser.cc" // lalr1.cc:636
        break;

      case 116: // condition

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstQuestionMark * > (); }
#line 859 "parser.cc" // lalr1.cc:636
        break;

      case 117: // functor_list

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUserDefinedFunctor * > (); }
#line 866 "parser.cc" // lalr1.cc:636
        break;

      case 118: // functor_args

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUserDefinedFunctor * > (); }
#line 873 "parser.cc" // lalr1.cc:636
        break;

      case 119: // recordlist

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRecordInit * > (); }
#line 880 "parser.cc" // lalr1.cc:636
        break;

      case 120: // non_empty_arg_list

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 887 "parser.cc" // lalr1.cc:636
        break;

      case 121: // arg_list

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 894 "parser.cc" // lalr1.cc:636
        break;

      case 122: // atom

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 901 "parser.cc" // lalr1.cc:636
        break;

      case 123: // literal

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 908 "parser.cc" // lalr1.cc:636
        break;

      case 124: // fact

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstClause * > (); }
#line 915 "parser.cc" // lalr1.cc:636
        break;

      case 125: // head

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstAtom*> > (); }
#line 922 "parser.cc" // lalr1.cc:636
        break;

      case 126: // term

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 929 "parser.cc" // lalr1.cc:636
        break;

      case 127: // conjunction

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 936 "parser.cc" // lalr1.cc:636
        break;

      case 128: // disjunction

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 943 "parser.cc" // lalr1.cc:636
        break;

      case 129: // body

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 950 "parser.cc" // lalr1.cc:636
        break;

      case 130: // exec_order_list

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionOrder * > (); }
#line 957 "parser.cc" // lalr1.cc:636
        break;

      case 131: // exec_order

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionOrder * > (); }
#line 964 "parser.cc" // lalr1.cc:636
        break;

      case 132: // exec_plan_list

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionPlan * > (); }
#line 971 "parser.cc" // lalr1.cc:636
        break;

      case 133: // exec_plan

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionPlan * > (); }
#line 978 "parser.cc" // lalr1.cc:636
        break;

      case 134: // rule_def

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstClause*> > (); }
#line 985 "parser.cc" // lalr1.cc:636
        break;

      case 135: // rule

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstClause*> > (); }
#line 992 "parser.cc" // lalr1.cc:636
        break;

      case 136: // type_param_list

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstTypeIdentifier> > (); }
#line 999 "parser.cc" // lalr1.cc:636
        break;

      case 137: // type_params

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstTypeIdentifier> > (); }
#line 1006 "parser.cc" // lalr1.cc:636
        break;

      case 138: // comp_type

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponentType * > (); }
#line 1013 "parser.cc" // lalr1.cc:636
        break;

      case 139: // component_head

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1020 "parser.cc" // lalr1.cc:636
        break;

      case 140: // component_body

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1027 "parser.cc" // lalr1.cc:636
        break;

      case 141: // component

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1034 "parser.cc" // lalr1.cc:636
        break;

      case 142: // comp_init

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponentInit * > (); }
#line 1041 "parser.cc" // lalr1.cc:636
        break;

      case 143: // comp_override

#line 215 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 1048 "parser.cc" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver, yyscanner));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 115: // arg
        yylhs.value.build< AstArgument * > ();
        break;

      case 120: // non_empty_arg_list
      case 121: // arg_list
      case 122: // atom
        yylhs.value.build< AstAtom * > ();
        break;

      case 124: // fact
        yylhs.value.build< AstClause * > ();
        break;

      case 139: // component_head
      case 140: // component_body
      case 141: // component
        yylhs.value.build< AstComponent * > ();
        break;

      case 142: // comp_init
        yylhs.value.build< AstComponentInit * > ();
        break;

      case 138: // comp_type
        yylhs.value.build< AstComponentType * > ();
        break;

      case 6: // "number"
        yylhs.value.build< AstDomain > ();
        break;

      case 94: // enumtype
        yylhs.value.build< AstEnumType * > ();
        break;

      case 130: // exec_order_list
      case 131: // exec_order
        yylhs.value.build< AstExecutionOrder * > ();
        break;

      case 132: // exec_plan_list
      case 133: // exec_plan
        yylhs.value.build< AstExecutionPlan * > ();
        break;

      case 99: // functor_decl
        yylhs.value.build< AstFunctorDeclaration * > ();
        break;

      case 109: // non_empty_key_value_pairs
      case 110: // key_value_pairs
      case 114: // iodirective_body
        yylhs.value.build< AstIO * > ();
        break;

      case 106: // lattice_asscoiation
        yylhs.value.build< AstLatticeAssociation * > ();
        break;

      case 107: // lattice_def
      case 108: // lattice_def_type
        yylhs.value.build< AstLatticeBinaryFunction * > ();
        break;

      case 89: // pragma
        yylhs.value.build< AstPragma * > ();
        break;

      case 116: // condition
        yylhs.value.build< AstQuestionMark * > ();
        break;

      case 119: // recordlist
        yylhs.value.build< AstRecordInit * > ();
        break;

      case 92: // recordtype
        yylhs.value.build< AstRecordType * > ();
        break;

      case 96: // non_empty_attributes
      case 97: // attributes
      case 104: // relation_body
        yylhs.value.build< AstRelation * > ();
        break;

      case 95: // rel_id
        yylhs.value.build< AstRelationIdentifier * > ();
        break;

      case 91: // type
        yylhs.value.build< AstType * > ();
        break;

      case 90: // type_id
        yylhs.value.build< AstTypeIdentifier * > ();
        break;

      case 93: // uniontype
        yylhs.value.build< AstUnionType * > ();
        break;

      case 117: // functor_list
      case 118: // functor_args
        yylhs.value.build< AstUserDefinedFunctor * > ();
        break;

      case 123: // literal
      case 126: // term
      case 127: // conjunction
      case 128: // disjunction
      case 129: // body
        yylhs.value.build< RuleBody * > ();
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 100: // functor_type
      case 101: // functor_typeargs
      case 143: // comp_override
        yylhs.value.build< std::string > ();
        break;

      case 125: // head
        yylhs.value.build< std::vector<AstAtom*> > ();
        break;

      case 134: // rule_def
      case 135: // rule
        yylhs.value.build< std::vector<AstClause*> > ();
        break;

      case 113: // iodirective_list
        yylhs.value.build< std::vector<AstIO *> > ();
        break;

      case 111: // load_head
        yylhs.value.build< std::vector<AstLoad *> > ();
        break;

      case 102: // relation_decl
      case 103: // relation_list
      case 105: // lattice_decl
        yylhs.value.build< std::vector<AstRelation *> > ();
        break;

      case 112: // store_head
        yylhs.value.build< std::vector<AstStore *> > ();
        break;

      case 136: // type_param_list
      case 137: // type_params
        yylhs.value.build< std::vector<AstTypeIdentifier> > ();
        break;

      case 98: // qualifiers
        yylhs.value.build< uint32_t > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 3:
#line 245 "./parser.yy" // lalr1.cc:859
    {
        driver.addType(std::unique_ptr<AstType>(yystack_[0].value.as< AstType * > ()));
    }
#line 1432 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 248 "./parser.yy" // lalr1.cc:859
    {
        driver.addFunctorDeclaration(std::unique_ptr<AstFunctorDeclaration>(yystack_[0].value.as< AstFunctorDeclaration * > ()));
    }
#line 1440 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 251 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) driver.addRelation(std::unique_ptr<AstRelation>(cur));
    }
#line 1448 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 254 "./parser.yy" // lalr1.cc:859
    {
    	std::cout << ".lat Lattice declaration here!\n";
    	for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) driver.addRelation(std::unique_ptr<AstRelation>(cur));
  	}
#line 1457 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 258 "./parser.yy" // lalr1.cc:859
    {
    	std::cout << ".let Lattice Asscoiation here!\n";
    	driver.addLatticeAssociation(std::unique_ptr<AstLatticeAssociation>(yystack_[0].value.as< AstLatticeAssociation * > ()));
  	}
#line 1466 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 262 "./parser.yy" // lalr1.cc:859
    {
  		std::cout << ".def Lattice binary function definition here!\n";
  		driver.addLatticeBinaryFunction(std::unique_ptr<AstLatticeBinaryFunction>(yystack_[0].value.as< AstLatticeBinaryFunction * > ()));
  	}
#line 1475 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 266 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstLoad *> > ()) driver.addLoad(std::unique_ptr<AstLoad>(cur));
    }
#line 1483 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 269 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstStore *> > ()) driver.addStore(std::unique_ptr<AstStore>(cur));
    }
#line 1491 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 272 "./parser.yy" // lalr1.cc:859
    {
        driver.addClause(std::unique_ptr<AstClause>(yystack_[0].value.as< AstClause * > ()));
    }
#line 1499 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 275 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstClause*> > ()) driver.addClause(std::unique_ptr<AstClause>(cur));
    }
#line 1507 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 278 "./parser.yy" // lalr1.cc:859
    {
        driver.addComponent(std::unique_ptr<AstComponent>(yystack_[0].value.as< AstComponent * > ()));
    }
#line 1515 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 281 "./parser.yy" // lalr1.cc:859
    {
        driver.addInstantiation(std::unique_ptr<AstComponentInit>(yystack_[0].value.as< AstComponentInit * > ()));
    }
#line 1523 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 284 "./parser.yy" // lalr1.cc:859
    {
        driver.addPragma(std::unique_ptr<AstPragma>(yystack_[0].value.as< AstPragma * > ()));
    }
#line 1531 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 287 "./parser.yy" // lalr1.cc:859
    {
    }
#line 1538 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 292 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstPragma * > () = new AstPragma(yystack_[1].value.as< std::string > (),yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstPragma * > ()->setSrcLoc(yylhs.location);
    }
#line 1547 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 297 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstPragma * > () = new AstPragma(yystack_[0].value.as< std::string > (), "");
        yylhs.value.as< AstPragma * > ()->setSrcLoc(yylhs.location);
    }
#line 1556 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 306 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstTypeIdentifier * > () = new AstTypeIdentifier(yystack_[0].value.as< std::string > ());
    }
#line 1564 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 309 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstTypeIdentifier * > () = yystack_[2].value.as< AstTypeIdentifier * > ();
        yylhs.value.as< AstTypeIdentifier * > ()->append(yystack_[0].value.as< std::string > ());
    }
#line 1573 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 316 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > (), true);
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1582 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 320 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > (), false);
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1591 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 324 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1600 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 328 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = yystack_[0].value.as< AstUnionType * > ();
        yylhs.value.as< AstType * > ()->setName(yystack_[2].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1610 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 333 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = yystack_[1].value.as< AstRecordType * > ();
        yylhs.value.as< AstType * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1620 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 338 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstRecordType();
        yylhs.value.as< AstType * > ()->setName(yystack_[3].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1630 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 343 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstType * > () = yystack_[1].value.as< AstEnumType * > ();
  		yylhs.value.as< AstType * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
        std::cout<<"Enum type declaration here!\n";
  	}
#line 1641 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 351 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordType * > () = new AstRecordType();
        yylhs.value.as< AstRecordType * > ()->add(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1650 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 355 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordType * > () = yystack_[4].value.as< AstRecordType * > ();
        yystack_[4].value.as< AstRecordType * > ()->add(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1659 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 361 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUnionType * > () = new AstUnionType();
        yylhs.value.as< AstUnionType * > ()->add(*yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1668 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 365 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUnionType * > () = yystack_[2].value.as< AstUnionType * > ();
        yystack_[2].value.as< AstUnionType * > ()->add(*yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1677 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 371 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstEnumType * > () = new AstEnumType();
  		yylhs.value.as< AstEnumType * > ()->add(yystack_[0].value.as< std::string > ());
  		// regard lattice enum as symbol
  		driver.getSymbolTable().lookup(yystack_[0].value.as< std::string > ());
  	}
#line 1688 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 377 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstEnumType * > () = yystack_[3].value.as< AstEnumType * > ();
  		yystack_[3].value.as< AstEnumType * > ()->add(yystack_[0].value.as< std::string > ());
  		// regard lattice enum as symbol
  		driver.getSymbolTable().lookup(yystack_[0].value.as< std::string > ());
  	}
#line 1699 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 388 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelationIdentifier * > () = new AstRelationIdentifier(yystack_[0].value.as< std::string > ());
    }
#line 1707 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 391 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelationIdentifier * > () = yystack_[2].value.as< AstRelationIdentifier * > ();
        yylhs.value.as< AstRelationIdentifier * > ()->append(yystack_[0].value.as< std::string > ());
    }
#line 1716 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 399 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = new AstRelation();
        AstAttribute *a = new AstAttribute(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ());
        a->setSrcLoc(yystack_[0].location);
        yylhs.value.as< AstRelation * > ()->addAttribute(std::unique_ptr<AstAttribute>(a));
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1728 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 406 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[4].value.as< AstRelation * > ();
        AstAttribute *a = new AstAttribute(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ());
        a->setSrcLoc(yystack_[0].location);
        yylhs.value.as< AstRelation * > ()->addAttribute(std::unique_ptr<AstAttribute>(a));
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1740 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 415 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[0].value.as< AstRelation * > ();
    }
#line 1748 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 418 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = new AstRelation();
    }
#line 1756 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 423 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & OUTPUT_RELATION) driver.error(yystack_[0].location, "output qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | OUTPUT_RELATION;
    }
#line 1765 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 427 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & INPUT_RELATION) driver.error(yystack_[0].location, "input qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | INPUT_RELATION;
    }
#line 1774 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 431 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & PRINTSIZE_RELATION) driver.error(yystack_[0].location, "printsize qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | PRINTSIZE_RELATION;
    }
#line 1783 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 435 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & OVERRIDABLE_RELATION) driver.error(yystack_[0].location, "overridable qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | OVERRIDABLE_RELATION;
    }
#line 1792 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 439 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & INLINE_RELATION) driver.error(yystack_[0].location, "inline qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | INLINE_RELATION;
    }
#line 1801 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 443 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | BRIE_RELATION;
    }
#line 1810 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 447 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | BTREE_RELATION;
    }
#line 1819 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 451 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | EQREL_RELATION;
    }
#line 1828 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 455 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< uint32_t > () = 0;
    }
#line 1836 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 460 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstFunctorDeclaration * > () = new AstFunctorDeclaration(yystack_[5].value.as< std::string > (), yystack_[3].value.as< std::string > ()+yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstFunctorDeclaration * > ()->setSrcLoc(yylhs.location);
    }
#line 1845 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 464 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstFunctorDeclaration * > () = new AstFunctorDeclaration(yystack_[4].value.as< std::string > (), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstFunctorDeclaration * > ()->setSrcLoc(yylhs.location);
    }
#line 1854 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 471 "./parser.yy" // lalr1.cc:859
    {
      if (yystack_[0].value.as< std::string > () == "number") {
          yylhs.value.as< std::string > () = "N";
      } else if (yystack_[0].value.as< std::string > () == "symbol") {
          yylhs.value.as< std::string > () = "S";
      } else driver.error(yystack_[0].location, "number or symbol identifier expected");
    }
#line 1866 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 481 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + yystack_[0].value.as< std::string > (); }
#line 1872 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 482 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();  }
#line 1878 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 486 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
    }
#line 1886 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 491 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().push_back(yystack_[0].value.as< AstRelation * > ());
    }
#line 1894 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 494 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
      auto tmp = yylhs.value.as< std::vector<AstRelation *> > ().back()->clone();
      tmp->setName(yystack_[2].value.as< std::string > ());
      tmp->setSrcLoc(yylhs.location);
      yylhs.value.as< std::vector<AstRelation *> > ().push_back(tmp);
    }
#line 1906 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 503 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[2].value.as< AstRelation * > ();
        yylhs.value.as< AstRelation * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstRelation * > ()->setQualifier(yystack_[0].value.as< uint32_t > ());
        yylhs.value.as< AstRelation * > ()->setSrcLoc(yylhs.location);
    }
#line 1917 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 511 "./parser.yy" // lalr1.cc:859
    {
    	yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
    	for (auto* cur : yylhs.value.as< std::vector<AstRelation *> > ()) {
          cur->setLattice();
      	}
  	}
#line 1928 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 519 "./parser.yy" // lalr1.cc:859
    {
    	yylhs.value.as< AstLatticeAssociation * > () = new AstLatticeAssociation(yystack_[14].value.as< std::string > ());
    	yylhs.value.as< AstLatticeAssociation * > ()->setALL(yystack_[9].value.as< std::string > (), yystack_[7].value.as< std::string > (), yystack_[5].value.as< std::string > (), yystack_[3].value.as< std::string > (), yystack_[1].value.as< std::string > ());
  	}
#line 1937 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 525 "./parser.yy" // lalr1.cc:859
    {
  // TODO
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[1].value.as< AstLatticeBinaryFunction * > ();
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setSrcLoc(yylhs.location);
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setName(yystack_[10].value.as< std::string > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addArg(yystack_[8].value.as< std::string > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addArg(yystack_[6].value.as< std::string > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setOutput(yystack_[3].value.as< std::string > ());
  	}
#line 1951 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 536 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = new AstLatticeBinaryFunction();	
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addPairMap(yystack_[5].value.as< AstArgument * > (), yystack_[3].value.as< AstArgument * > (), yystack_[0].value.as< AstArgument * > ());
  	}
#line 1960 "parser.cc" // lalr1.cc:859
    break;

  case 62:
#line 540 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[9].value.as< AstLatticeBinaryFunction * > ();
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addPairMap(yystack_[5].value.as< AstArgument * > (), yystack_[3].value.as< AstArgument * > (), yystack_[0].value.as< AstArgument * > ());
  	}
#line 1969 "parser.cc" // lalr1.cc:859
    break;

  case 63:
#line 544 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[5].value.as< AstLatticeBinaryFunction * > ();
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addPairMap(NULL, NULL, yystack_[0].value.as< AstArgument * > ());
  	}
#line 1978 "parser.cc" // lalr1.cc:859
    break;

  case 64:
#line 551 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 1987 "parser.cc" // lalr1.cc:859
    break;

  case 65:
#line 555 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 1996 "parser.cc" // lalr1.cc:859
    break;

  case 66:
#line 559 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 2005 "parser.cc" // lalr1.cc:859
    break;

  case 67:
#line 563 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 2014 "parser.cc" // lalr1.cc:859
    break;

  case 68:
#line 567 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "true");
    }
#line 2023 "parser.cc" // lalr1.cc:859
    break;

  case 69:
#line 571 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "true");
    }
#line 2032 "parser.cc" // lalr1.cc:859
    break;

  case 70:
#line 575 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "false");
    }
#line 2041 "parser.cc" // lalr1.cc:859
    break;

  case 71:
#line 579 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "false");
    }
#line 2050 "parser.cc" // lalr1.cc:859
    break;

  case 72:
#line 585 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[0].value.as< AstIO * > ();
    }
#line 2058 "parser.cc" // lalr1.cc:859
    break;

  case 73:
#line 588 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->setSrcLoc(yylhs.location);
    }
#line 2067 "parser.cc" // lalr1.cc:859
    break;

  case 74:
#line 594 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstLoad *> > ().push_back(new AstLoad(*cur));
          delete cur;
      }
    }
#line 2078 "parser.cc" // lalr1.cc:859
    break;

  case 75:
#line 601 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstStore *> > ().push_back(new AstStore(*cur));
          delete cur;
      }
    }
#line 2089 "parser.cc" // lalr1.cc:859
    break;

  case 76:
#line 607 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstStore *> > ().push_back(new AstPrintSize(*cur));
          delete cur;
      }
    }
#line 2100 "parser.cc" // lalr1.cc:859
    break;

  case 77:
#line 615 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstIO *> > ().push_back(yystack_[0].value.as< AstIO * > ());
    }
#line 2108 "parser.cc" // lalr1.cc:859
    break;

  case 78:
#line 618 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstIO *> > ().swap(yystack_[0].value.as< std::vector<AstIO *> > ());
      auto tmp = yylhs.value.as< std::vector<AstIO *> > ().back()->clone();
      tmp->setName(yystack_[2].value.as< std::string > ());
      tmp->setSrcLoc(yystack_[2].location);
      yylhs.value.as< std::vector<AstIO *> > ().push_back(tmp);
    }
#line 2120 "parser.cc" // lalr1.cc:859
    break;

  case 79:
#line 627 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[1].value.as< AstIO * > ();
        yystack_[1].value.as< AstIO * > ()->addName(*yystack_[3].value.as< AstRelationIdentifier * > ());
        yystack_[1].value.as< AstIO * > ()->setSrcLoc(yystack_[3].location);
        delete yystack_[3].value.as< AstRelationIdentifier * > ();
    }
#line 2131 "parser.cc" // lalr1.cc:859
    break;

  case 80:
#line 633 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->setName(*yystack_[0].value.as< AstRelationIdentifier * > ());
        yylhs.value.as< AstIO * > ()->setSrcLoc(yystack_[0].location);
        delete yystack_[0].value.as< AstRelationIdentifier * > ();
    }
#line 2142 "parser.cc" // lalr1.cc:859
    break;

  case 81:
#line 642 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstStringConstant(driver.getSymbolTable(), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2151 "parser.cc" // lalr1.cc:859
    break;

  case 82:
#line 646 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstUnnamedVariable();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2160 "parser.cc" // lalr1.cc:859
    break;

  case 83:
#line 650 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstCounter();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2169 "parser.cc" // lalr1.cc:859
    break;

  case 84:
#line 654 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[0].value.as< AstUserDefinedFunctor * > ();
        yystack_[0].value.as< AstUserDefinedFunctor * > ()->setName(yystack_[1].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2179 "parser.cc" // lalr1.cc:859
    break;

  case 85:
#line 659 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstVariable(yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2188 "parser.cc" // lalr1.cc:859
    break;

  case 86:
#line 663 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstNumberConstant(yystack_[0].value.as< AstDomain > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2197 "parser.cc" // lalr1.cc:859
    break;

  case 87:
#line 667 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[1].value.as< AstArgument * > ();
    }
#line 2205 "parser.cc" // lalr1.cc:859
    break;

  case 88:
#line 670 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2214 "parser.cc" // lalr1.cc:859
    break;

  case 89:
#line 674 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BXOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2223 "parser.cc" // lalr1.cc:859
    break;

  case 90:
#line 678 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BAND, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2232 "parser.cc" // lalr1.cc:859
    break;

  case 91:
#line 682 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2241 "parser.cc" // lalr1.cc:859
    break;

  case 92:
#line 686 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LAND, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2250 "parser.cc" // lalr1.cc:859
    break;

  case 93:
#line 690 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::ADD, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2259 "parser.cc" // lalr1.cc:859
    break;

  case 94:
#line 694 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::SUB, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2268 "parser.cc" // lalr1.cc:859
    break;

  case 95:
#line 698 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MUL, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2277 "parser.cc" // lalr1.cc:859
    break;

  case 96:
#line 702 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::DIV, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2286 "parser.cc" // lalr1.cc:859
    break;

  case 97:
#line 706 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MOD, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2295 "parser.cc" // lalr1.cc:859
    break;

  case 98:
#line 710 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::EXP, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2304 "parser.cc" // lalr1.cc:859
    break;

  case 99:
#line 714 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MAX, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2313 "parser.cc" // lalr1.cc:859
    break;

  case 100:
#line 718 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MIN, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2322 "parser.cc" // lalr1.cc:859
    break;

  case 101:
#line 722 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::CAT, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2331 "parser.cc" // lalr1.cc:859
    break;

  case 102:
#line 726 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::ORD, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2340 "parser.cc" // lalr1.cc:859
    break;

  case 103:
#line 730 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::STRLEN, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2349 "parser.cc" // lalr1.cc:859
    break;

  case 104:
#line 734 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::TONUMBER, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2358 "parser.cc" // lalr1.cc:859
    break;

  case 105:
#line 738 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::TOSTRING, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2367 "parser.cc" // lalr1.cc:859
    break;

  case 106:
#line 742 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::SUBSTR,
                std::unique_ptr<AstArgument>(yystack_[5].value.as< AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2379 "parser.cc" // lalr1.cc:859
    break;

  case 107:
#line 749 "./parser.yy" // lalr1.cc:859
    {
  		yystack_[4].value.as< AstQuestionMark * > ()->setReturns(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
  		yylhs.value.as< AstArgument * > () = yystack_[4].value.as< AstQuestionMark * > ();
    }
#line 2388 "parser.cc" // lalr1.cc:859
    break;

  case 108:
#line 753 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstTypeCast(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2397 "parser.cc" // lalr1.cc:859
    break;

  case 109:
#line 757 "./parser.yy" // lalr1.cc:859
    {
        std::unique_ptr<AstArgument> arg;
        if (const AstNumberConstant* original = dynamic_cast<const AstNumberConstant*>(yystack_[0].value.as< AstArgument * > ())) {
            yylhs.value.as< AstArgument * > () = new AstNumberConstant(-1*original->getIndex());
            yylhs.value.as< AstArgument * > ()->setSrcLoc(yystack_[0].value.as< AstArgument * > ()->getSrcLoc());
            delete yystack_[0].value.as< AstArgument * > ();
        } else {
            yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::NEG, std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
            yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
        }
    }
#line 2413 "parser.cc" // lalr1.cc:859
    break;

  case 110:
#line 768 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BNOT, std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2422 "parser.cc" // lalr1.cc:859
    break;

  case 111:
#line 772 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LNOT, std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2431 "parser.cc" // lalr1.cc:859
    break;

  case 112:
#line 776 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstRecordInit();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2440 "parser.cc" // lalr1.cc:859
    break;

  case 113:
#line 780 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[1].value.as< AstRecordInit * > ();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2449 "parser.cc" // lalr1.cc:859
    break;

  case 114:
#line 784 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstNullConstant();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2458 "parser.cc" // lalr1.cc:859
    break;

  case 115:
#line 788 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::count);
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2469 "parser.cc" // lalr1.cc:859
    break;

  case 116:
#line 794 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::count);
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }
        for(const auto& cur : bodies[0]->getBodyLiterals()) {
            res->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];
        delete yystack_[1].value.as< RuleBody * > ();
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2489 "parser.cc" // lalr1.cc:859
    break;

  case 117:
#line 809 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::sum);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2501 "parser.cc" // lalr1.cc:859
    break;

  case 118:
#line 816 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::sum);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[4].value.as< AstArgument * > ()));
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }
        for(const auto& cur : bodies[0]->getBodyLiterals()) {
	    res->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];
        delete yystack_[1].value.as< RuleBody * > ();
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2522 "parser.cc" // lalr1.cc:859
    break;

  case 119:
#line 832 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::min);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2534 "parser.cc" // lalr1.cc:859
    break;

  case 120:
#line 839 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::min);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[4].value.as< AstArgument * > ()));
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }
        for(const auto& cur : bodies[0]->getBodyLiterals()) {
            res->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];
        delete yystack_[1].value.as< RuleBody * > ();
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2555 "parser.cc" // lalr1.cc:859
    break;

  case 121:
#line 855 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::max);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2567 "parser.cc" // lalr1.cc:859
    break;

  case 122:
#line 862 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::max);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[4].value.as< AstArgument * > ()));
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }
        for(const auto& cur : bodies[0]->getBodyLiterals()) {
            res->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];
        delete yystack_[1].value.as< RuleBody * > ();
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2588 "parser.cc" // lalr1.cc:859
    break;

  case 123:
#line 878 "./parser.yy" // lalr1.cc:859
    {
        std::cerr << "ERROR: '" << yystack_[3].value.as< std::string > () << "' is a keyword reserved for future implementation!" << std::endl;
        exit(1);
    }
#line 2597 "parser.cc" // lalr1.cc:859
    break;

  case 124:
#line 884 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(AstQuestionMark::CompOp::EQ, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2606 "parser.cc" // lalr1.cc:859
    break;

  case 125:
#line 888 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(AstQuestionMark::CompOp::NE, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2615 "parser.cc" // lalr1.cc:859
    break;

  case 126:
#line 892 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(AstQuestionMark::CompOp::LT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2624 "parser.cc" // lalr1.cc:859
    break;

  case 127:
#line 896 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(AstQuestionMark::CompOp::LE, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2633 "parser.cc" // lalr1.cc:859
    break;

  case 128:
#line 900 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(AstQuestionMark::CompOp::GT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2642 "parser.cc" // lalr1.cc:859
    break;

  case 129:
#line 904 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(AstQuestionMark::CompOp::GE, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2651 "parser.cc" // lalr1.cc:859
    break;

  case 130:
#line 912 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = new AstUserDefinedFunctor();
    }
#line 2659 "parser.cc" // lalr1.cc:859
    break;

  case 131:
#line 915 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = yystack_[1].value.as< AstUserDefinedFunctor * > ();
    }
#line 2667 "parser.cc" // lalr1.cc:859
    break;

  case 132:
#line 921 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = new AstUserDefinedFunctor();
        yylhs.value.as< AstUserDefinedFunctor * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2676 "parser.cc" // lalr1.cc:859
    break;

  case 133:
#line 925 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = yystack_[2].value.as< AstUserDefinedFunctor * > ();
        yylhs.value.as< AstUserDefinedFunctor * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2685 "parser.cc" // lalr1.cc:859
    break;

  case 134:
#line 932 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordInit * > () = new AstRecordInit();
        yylhs.value.as< AstRecordInit * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2694 "parser.cc" // lalr1.cc:859
    break;

  case 135:
#line 936 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordInit * > () = yystack_[2].value.as< AstRecordInit * > ();
        yylhs.value.as< AstRecordInit * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2703 "parser.cc" // lalr1.cc:859
    break;

  case 136:
#line 942 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = new AstAtom();
        yylhs.value.as< AstAtom * > ()->addArgument(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2712 "parser.cc" // lalr1.cc:859
    break;

  case 137:
#line 946 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[2].value.as< AstAtom * > ();
        yylhs.value.as< AstAtom * > ()->addArgument(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2721 "parser.cc" // lalr1.cc:859
    break;

  case 138:
#line 952 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[0].value.as< AstAtom * > ();
    }
#line 2729 "parser.cc" // lalr1.cc:859
    break;

  case 139:
#line 955 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = new AstAtom();
    }
#line 2737 "parser.cc" // lalr1.cc:859
    break;

  case 140:
#line 960 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[1].value.as< AstAtom * > ();
        yystack_[1].value.as< AstAtom * > ()->setName(*yystack_[3].value.as< AstRelationIdentifier * > ());
        delete yystack_[3].value.as< AstRelationIdentifier * > ();
        yylhs.value.as< AstAtom * > ()->setSrcLoc(yylhs.location);
    }
#line 2748 "parser.cc" // lalr1.cc:859
    break;

  case 141:
#line 969 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(yystack_[1].value.as< std::string > (), std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2758 "parser.cc" // lalr1.cc:859
    break;

  case 142:
#line 974 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::LT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2768 "parser.cc" // lalr1.cc:859
    break;

  case 143:
#line 979 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::GT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2778 "parser.cc" // lalr1.cc:859
    break;

  case 144:
#line 984 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::EQ, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2788 "parser.cc" // lalr1.cc:859
    break;

  case 145:
#line 989 "./parser.yy" // lalr1.cc:859
    {
        yystack_[0].value.as< AstAtom * > ()->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::atom(yystack_[0].value.as< AstAtom * > ()));
    }
#line 2797 "parser.cc" // lalr1.cc:859
    break;

  case 146:
#line 993 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::MATCH, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2807 "parser.cc" // lalr1.cc:859
    break;

  case 147:
#line 998 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::CONTAINS, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2817 "parser.cc" // lalr1.cc:859
    break;

  case 148:
#line 1003 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBooleanConstraint(true);
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2827 "parser.cc" // lalr1.cc:859
    break;

  case 149:
#line 1008 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBooleanConstraint(false);
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2837 "parser.cc" // lalr1.cc:859
    break;

  case 150:
#line 1016 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstClause * > () = new AstClause();
        yylhs.value.as< AstClause * > ()->setHead(std::unique_ptr<AstAtom>(yystack_[1].value.as< AstAtom * > ()));
        yylhs.value.as< AstClause * > ()->setSrcLoc(yylhs.location);
    }
#line 2847 "parser.cc" // lalr1.cc:859
    break;

  case 151:
#line 1024 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstAtom*> > ().push_back(yystack_[0].value.as< AstAtom * > ());
    }
#line 2855 "parser.cc" // lalr1.cc:859
    break;

  case 152:
#line 1027 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstAtom*> > ().swap(yystack_[2].value.as< std::vector<AstAtom*> > ());
        yylhs.value.as< std::vector<AstAtom*> > ().push_back(yystack_[0].value.as< AstAtom * > ());
    }
#line 2864 "parser.cc" // lalr1.cc:859
    break;

  case 153:
#line 1034 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2872 "parser.cc" // lalr1.cc:859
    break;

  case 154:
#line 1037 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->negate();
    }
#line 2881 "parser.cc" // lalr1.cc:859
    break;

  case 155:
#line 1041 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[1].value.as< RuleBody * > ();
    }
#line 2889 "parser.cc" // lalr1.cc:859
    break;

  case 156:
#line 1047 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2897 "parser.cc" // lalr1.cc:859
    break;

  case 157:
#line 1050 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[2].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->conjunct(std::move(*yystack_[0].value.as< RuleBody * > ()));
        delete yystack_[0].value.as< RuleBody * > ();
    }
#line 2907 "parser.cc" // lalr1.cc:859
    break;

  case 158:
#line 1058 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2915 "parser.cc" // lalr1.cc:859
    break;

  case 159:
#line 1061 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[2].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->disjunct(std::move(*yystack_[0].value.as< RuleBody * > ()));
        delete yystack_[0].value.as< RuleBody * > ();
    }
#line 2925 "parser.cc" // lalr1.cc:859
    break;

  case 160:
#line 1069 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2932 "parser.cc" // lalr1.cc:859
    break;

  case 161:
#line 1074 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = new AstExecutionOrder();
        yylhs.value.as< AstExecutionOrder * > ()->appendAtomIndex(yystack_[0].value.as< AstDomain > ());
    }
#line 2941 "parser.cc" // lalr1.cc:859
    break;

  case 162:
#line 1078 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = yystack_[2].value.as< AstExecutionOrder * > ();
        yylhs.value.as< AstExecutionOrder * > ()->appendAtomIndex(yystack_[0].value.as< AstDomain > ());
    }
#line 2950 "parser.cc" // lalr1.cc:859
    break;

  case 163:
#line 1085 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = yystack_[1].value.as< AstExecutionOrder * > ();
        yylhs.value.as< AstExecutionOrder * > ()->setSrcLoc(yylhs.location);
    }
#line 2959 "parser.cc" // lalr1.cc:859
    break;

  case 164:
#line 1092 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = new AstExecutionPlan();
        yylhs.value.as< AstExecutionPlan * > ()->setOrderFor(yystack_[2].value.as< AstDomain > (), std::unique_ptr<AstExecutionOrder>(yystack_[0].value.as< AstExecutionOrder * > ()));
    }
#line 2968 "parser.cc" // lalr1.cc:859
    break;

  case 165:
#line 1096 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = yystack_[4].value.as< AstExecutionPlan * > ();
        yylhs.value.as< AstExecutionPlan * > ()->setOrderFor(yystack_[2].value.as< AstDomain > (), std::unique_ptr<AstExecutionOrder>(yystack_[0].value.as< AstExecutionOrder * > ()));
    }
#line 2977 "parser.cc" // lalr1.cc:859
    break;

  case 166:
#line 1103 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = yystack_[0].value.as< AstExecutionPlan * > ();
        yylhs.value.as< AstExecutionPlan * > ()->setSrcLoc(yylhs.location);
    }
#line 2986 "parser.cc" // lalr1.cc:859
    break;

  case 167:
#line 1110 "./parser.yy" // lalr1.cc:859
    {
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        for(const auto& head : yystack_[3].value.as< std::vector<AstAtom*> > ()) {
            for(AstClause* body : bodies) {
                AstClause* cur = body->clone();
                cur->setHead(std::unique_ptr<AstAtom>(head->clone()));
                cur->setSrcLoc(yylhs.location);
                cur->setGenerated(yystack_[3].value.as< std::vector<AstAtom*> > ().size() != 1 || bodies.size() != 1);
                yylhs.value.as< std::vector<AstClause*> > ().push_back(cur);
            }
        }
        for(auto& head : yystack_[3].value.as< std::vector<AstAtom*> > ()) {
            delete head;
        }
        for(AstClause* body : bodies) {
            delete body;
        }
        delete yystack_[1].value.as< RuleBody * > ();
    }
#line 3010 "parser.cc" // lalr1.cc:859
    break;

  case 168:
#line 1132 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[0].value.as< std::vector<AstClause*> > ();
    }
#line 3018 "parser.cc" // lalr1.cc:859
    break;

  case 169:
#line 1135 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[1].value.as< std::vector<AstClause*> > ();
        for(const auto& cur : yylhs.value.as< std::vector<AstClause*> > ()) cur->setFixedExecutionPlan();
    }
#line 3027 "parser.cc" // lalr1.cc:859
    break;

  case 170:
#line 1139 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[1].value.as< std::vector<AstClause*> > ();
        for(const auto& cur : yylhs.value.as< std::vector<AstClause*> > ()) cur->setExecutionPlan(std::unique_ptr<AstExecutionPlan>(yystack_[0].value.as< AstExecutionPlan * > ()->clone()));
    }
#line 3036 "parser.cc" // lalr1.cc:859
    break;

  case 171:
#line 1147 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > ().push_back(yystack_[0].value.as< std::string > ());
    }
#line 3044 "parser.cc" // lalr1.cc:859
    break;

  case 172:
#line 1150 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > () = yystack_[2].value.as< std::vector<AstTypeIdentifier> > ();
        yylhs.value.as< std::vector<AstTypeIdentifier> > ().push_back(*yystack_[0].value.as< AstTypeIdentifier * > ());
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 3054 "parser.cc" // lalr1.cc:859
    break;

  case 173:
#line 1157 "./parser.yy" // lalr1.cc:859
    {
    }
#line 3061 "parser.cc" // lalr1.cc:859
    break;

  case 174:
#line 1159 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > () = yystack_[1].value.as< std::vector<AstTypeIdentifier> > ();
    }
#line 3069 "parser.cc" // lalr1.cc:859
    break;

  case 175:
#line 1166 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponentType * > () = new AstComponentType(yystack_[1].value.as< std::string > (),yystack_[0].value.as< std::vector<AstTypeIdentifier> > ());
    }
#line 3077 "parser.cc" // lalr1.cc:859
    break;

  case 176:
#line 1173 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = new AstComponent();
        yylhs.value.as< AstComponent * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 3086 "parser.cc" // lalr1.cc:859
    break;

  case 177:
#line 1177 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[2].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addBaseComponent(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 3095 "parser.cc" // lalr1.cc:859
    break;

  case 178:
#line 1181 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[2].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addBaseComponent(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 3104 "parser.cc" // lalr1.cc:859
    break;

  case 179:
#line 1187 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addType(std::unique_ptr<AstType>(yystack_[0].value.as< AstType * > ()));
    }
#line 3113 "parser.cc" // lalr1.cc:859
    break;

  case 180:
#line 1191 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) yylhs.value.as< AstComponent * > ()->addRelation(std::unique_ptr<AstRelation>(cur));
    }
#line 3122 "parser.cc" // lalr1.cc:859
    break;

  case 181:
#line 1195 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstLoad *> > ()) yylhs.value.as< AstComponent * > ()->addLoad(std::unique_ptr<AstLoad>(cur));
    }
#line 3131 "parser.cc" // lalr1.cc:859
    break;

  case 182:
#line 1199 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstStore *> > ()) yylhs.value.as< AstComponent * > ()->addStore(std::unique_ptr<AstStore>(cur));
    }
#line 3140 "parser.cc" // lalr1.cc:859
    break;

  case 183:
#line 1203 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addClause(std::unique_ptr<AstClause>(yystack_[0].value.as< AstClause * > ()));
    }
#line 3149 "parser.cc" // lalr1.cc:859
    break;

  case 184:
#line 1207 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstClause*> > ()) {
            yylhs.value.as< AstComponent * > ()->addClause(std::unique_ptr<AstClause>(cur));
        }
    }
#line 3160 "parser.cc" // lalr1.cc:859
    break;

  case 185:
#line 1213 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addOverride(yystack_[0].value.as< std::string > ());
    }
#line 3169 "parser.cc" // lalr1.cc:859
    break;

  case 186:
#line 1217 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addComponent(std::unique_ptr<AstComponent>(yystack_[0].value.as< AstComponent * > ()));
    }
#line 3178 "parser.cc" // lalr1.cc:859
    break;

  case 187:
#line 1221 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addInstantiation(std::unique_ptr<AstComponentInit>(yystack_[0].value.as< AstComponentInit * > ()));
    }
#line 3187 "parser.cc" // lalr1.cc:859
    break;

  case 188:
#line 1225 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = new AstComponent();
    }
#line 3195 "parser.cc" // lalr1.cc:859
    break;

  case 189:
#line 1230 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[3].value.as< AstComponent * > ()->getComponentType()->clone()));
        yylhs.value.as< AstComponent * > ()->copyBaseComponents(yystack_[3].value.as< AstComponent * > ());
        delete yystack_[3].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->setSrcLoc(yylhs.location);
    }
#line 3207 "parser.cc" // lalr1.cc:859
    break;

  case 190:
#line 1240 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponentInit * > () = new AstComponentInit();
        yylhs.value.as< AstComponentInit * > ()->setInstanceName(yystack_[2].value.as< std::string > ());
        yylhs.value.as< AstComponentInit * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
        yylhs.value.as< AstComponentInit * > ()->setSrcLoc(yylhs.location);
    }
#line 3218 "parser.cc" // lalr1.cc:859
    break;

  case 191:
#line 1249 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
}
#line 3226 "parser.cc" // lalr1.cc:859
    break;


#line 3230 "parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short int parser::yypact_ninf_ = -246;

  const short int parser::yytable_ninf_ = -129;

  const short int
  parser::yypact_[] =
  {
    -246,    55,   185,  -246,  -246,    48,    58,    58,    78,    81,
     105,   110,   110,   110,   113,   133,   140,   143,   153,   158,
    -246,  -246,    43,  -246,  -246,  -246,  -246,  -246,  -246,  -246,
     100,  -246,   -13,  -246,    40,   -32,  -246,  -246,   162,   -24,
    -246,  -246,  -246,    93,   109,   111,   108,    44,  -246,  -246,
    -246,  -246,   118,   119,    97,  -246,   120,  -246,  -246,   556,
     183,  -246,   156,   184,  -246,   186,  -246,   140,   140,  -246,
    -246,   190,    58,   115,   192,     6,   110,   193,    14,   126,
     195,  -246,   140,   142,  -246,  -246,  -246,   145,   152,   155,
     172,   623,   690,   170,   556,   174,   175,  -246,   261,  -246,
    -246,   556,   556,   232,   556,   556,  1672,   179,  -246,    27,
    -246,    47,   180,   181,  -246,  -246,   156,   156,   315,  -246,
    -246,  -246,   182,   178,   187,  -246,   196,   188,  -246,  -246,
     257,   197,  -246,    52,  -246,   176,   191,  -246,   200,   194,
     218,  -246,   221,  -246,    82,  -246,    11,   225,   198,   161,
    -246,   -36,  -246,   556,   556,   556,   556,   556,   556,   804,
     556,   835,     1,   866,   556,   556,  -246,  1672,    38,   -14,
     897,   231,   -14,   -14,   242,   556,   556,   226,   556,   556,
     556,   556,   556,   355,   422,   556,   556,   556,   556,   556,
     556,  -246,   556,   556,   556,  -246,   711,   -27,   556,   556,
     355,   422,   156,   156,  -246,   244,   249,   287,  -246,  -246,
    -246,  -246,  -246,  -246,    40,  -246,  -246,  -246,   300,  -246,
     301,   250,   307,   312,   312,   256,    20,  -246,   318,   262,
    -246,    49,   321,   300,   322,    -6,   300,  -246,   928,   959,
     990,  1021,  1052,   742,     5,   773,     7,   156,  -246,     8,
    1083,  1114,  -246,   556,  -246,   489,  -246,  -246,    79,    79,
     556,  1672,   -14,   -14,   -14,   -14,   556,  1672,   556,  1672,
    1795,  1749,  1773,  1725,  1699,  1145,  1672,  1176,  1207,  -246,
    1672,  1238,  1269,  1300,  -246,   182,   314,  -246,   265,  -246,
     225,   259,   266,   327,   272,  -246,  -246,   312,  -246,  -246,
    -246,  -246,   267,   300,  -246,   330,  -246,   225,  -246,   252,
    -246,   225,  -246,   556,  -246,  -246,   556,   556,   156,  -246,
     556,   156,  -246,   263,   156,  -246,  -246,  -246,  1672,  -246,
    1672,    91,  1672,  1672,  1672,   556,   556,   556,  -246,    95,
     244,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,   300,
     276,   277,  -246,    23,   225,   279,   334,  1331,  1362,  1393,
     269,  1424,   273,  -246,   274,  -246,   556,    17,  1455,  1486,
    -246,   340,  -246,   225,   344,   345,  -246,  -246,  -246,  -246,
     300,  -246,  -246,   556,  -246,  -246,  -246,  -246,  -246,  1672,
    -246,  -246,  -246,   289,   280,   225,  1517,   350,   281,  -246,
     294,   306,    -3,   363,   556,   285,  -246,   308,  1548,     0,
     379,   556,   323,   556,   337,  1579,   556,  1610,  -246,   329,
    1672,   556,   556,  1641,  1672,   333,   556,  1672
  };

  const unsigned char
  parser::yydefact_[] =
  {
      16,     0,     2,     1,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     3,     0,     4,     5,     6,     7,     8,     9,    10,
     151,    11,     0,   168,    12,     0,    13,    14,    18,     0,
      54,    55,    58,     0,     0,     0,    34,    80,    74,    77,
      75,    76,    23,     0,   173,   176,     0,    21,    22,   139,
       0,   150,     0,     0,   169,     0,   170,     0,     0,   188,
      17,    39,     0,     0,     0,     0,     0,    73,     0,     0,
       0,   175,     0,     0,    81,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,    82,
      83,     0,     0,     0,     0,     0,   136,     0,   138,     0,
      35,    85,     0,     0,   148,   149,     0,     0,     0,   145,
     153,   156,   158,   160,     0,   152,     0,   166,   178,   177,
       0,     0,    38,     0,    56,     0,     0,    51,     0,    53,
       0,    78,     0,    72,     0,    19,     0,    30,    24,     0,
     171,     0,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,   134,     0,   109,
       0,     0,   110,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   140,     0,     0,     0,   154,     0,     0,     0,     0,
       0,     0,     0,     0,   167,     0,     0,     0,   189,   179,
     180,   181,   182,   183,   184,   186,   187,   185,     0,    48,
       0,     0,     0,     0,     0,     0,     0,    79,     0,     0,
      26,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,     0,
       0,     0,   113,     0,    87,     0,    84,   108,    93,    94,
       0,   124,    95,    96,    98,    97,     0,   126,     0,   128,
      90,    88,    89,    92,    91,     0,   137,     0,     0,   155,
     141,   144,   142,   143,   157,   159,     0,   164,     0,   191,
      36,    57,     0,     0,     0,    50,    52,     0,    64,    66,
      68,    70,     0,     0,    25,     0,    20,    31,    32,     0,
      27,   172,   123,     0,   102,   103,     0,     0,     0,   119,
       0,     0,   121,     0,     0,   117,   104,   105,   135,   130,
     132,     0,   125,   127,   129,     0,     0,     0,   161,     0,
       0,    40,    41,    42,    45,    46,    47,    43,    44,     0,
       0,     0,    49,     0,    28,     0,     0,     0,     0,     0,
       0,     0,     0,   116,     0,   131,     0,   107,     0,     0,
     163,     0,   165,    37,     0,     0,    65,    67,    69,    71,
       0,    33,   101,     0,   100,   120,    99,   122,   118,   133,
     146,   147,   162,     0,     0,    29,     0,     0,     0,   106,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,     0,
      63,     0,     0,     0,    61,     0,     0,    62
  };

  const short int
  parser::yypgoto_[] =
  {
    -246,  -246,  -246,  -246,  -213,   258,  -246,  -246,  -246,    -4,
    -246,  -246,  -246,  -246,  -220,   177,   270,    10,  -246,  -246,
    -246,  -246,  -246,  -246,  -246,   278,   283,     9,  -246,   -59,
    -246,  -246,  -246,  -246,  -246,  -246,     2,  -246,   284,  -246,
    -115,   201,   299,  -245,  -246,    66,  -246,  -246,  -246,   288,
    -246,  -246,   -53,  -246,  -246,   290,   291,  -246
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     1,     2,    20,   147,    21,   231,   148,   235,    22,
     132,   133,   291,    23,   139,   140,    24,    40,    41,    25,
      26,    27,   402,   143,   144,    28,    29,    48,    49,   118,
     107,   256,   331,   168,   108,   109,   119,   120,    31,    32,
     121,   122,   123,   124,   339,   287,   127,    66,    33,    34,
     151,    81,    55,    35,   130,    36,    37,   217
  };

  const short int
  parser::yytable_[] =
  {
     106,   195,   323,   295,    30,   290,     4,    47,    47,    47,
       4,   137,     4,     4,   128,   129,   229,    42,    62,   145,
     307,    50,    51,   311,   298,   299,   236,   376,   377,   152,
      67,    68,   159,   161,   279,   163,    71,   203,    72,   167,
     237,    69,   169,   170,   177,   172,   173,   300,   301,    63,
     378,   379,    38,   178,   412,     3,   309,   181,   196,   405,
     413,   183,   184,    39,   230,   125,   146,   138,   310,    64,
      65,   406,    47,   360,   247,   177,   362,   352,   318,   364,
     321,   324,   134,    43,   178,   141,    44,   284,   191,   192,
     354,   252,   183,   184,   238,   239,   240,   241,   242,   243,
     253,   245,   304,    59,    77,   250,   251,   -34,    60,    60,
      45,   305,   -34,   219,   220,    46,   258,   259,    52,   261,
     262,   263,   264,   265,   267,   269,   270,   271,   272,   273,
     274,   275,    30,   276,   277,   278,   373,   177,    53,   280,
     281,   282,   283,   227,   228,    54,   178,   179,    56,   180,
     181,   182,   365,   366,   183,   184,   370,   371,    57,    83,
      84,   111,    86,    58,   248,    61,    70,   395,    73,    74,
      76,    75,    80,   112,   113,    87,    88,    89,    90,    91,
      92,    93,    94,   114,   115,    78,    79,    82,   110,     4,
       4,   135,   126,     5,   328,   131,   330,   136,   142,   149,
     150,   332,   153,    95,    96,   154,    97,   333,    98,   334,
      99,   100,   155,   101,   116,   156,   117,     6,     7,     8,
       9,    10,    11,    12,    13,   103,    14,    15,    16,    17,
      18,    19,   157,   162,   164,   165,   104,   171,   190,   105,
     193,   194,   203,   221,   202,   234,   319,   257,   322,   233,
     206,   325,   204,   222,   357,   288,   224,   358,   359,   205,
     218,   361,     4,   223,    83,    84,    85,    86,   341,   342,
     343,   344,   345,   346,   347,   348,   367,   368,   369,   225,
      87,    88,    89,    90,    91,    92,    93,    94,   226,     6,
     232,   255,   289,   260,    11,    12,    13,   207,    14,    15,
      16,    17,    18,    19,   286,   145,   292,   389,    95,    96,
     293,    97,   294,    98,   166,    99,   100,   137,   101,   297,
     338,   102,   198,   302,   396,   303,   306,   308,   340,   349,
     103,   208,   350,   351,   353,   355,   356,   363,   374,   381,
     375,   104,   380,   385,   105,   408,   392,   387,   388,   393,
     394,   397,   415,   398,   417,   400,   403,   420,    83,    84,
      85,    86,   423,   424,   174,   401,   404,   427,   407,   409,
     410,   175,   176,   177,    87,    88,    89,    90,    91,    92,
      93,    94,   199,   179,   414,   180,   181,   182,   209,   416,
     200,   201,   185,   186,   187,   422,   188,   189,   418,   426,
     210,   296,    95,    96,   285,    97,   372,    98,   211,    99,
     100,     0,   101,   212,   213,   102,   197,     0,   214,     0,
     215,   216,   266,     0,   103,    83,    84,    85,    86,     0,
       0,     0,     0,     0,     0,   104,     0,     0,   105,     0,
       0,    87,    88,    89,    90,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,     0,    97,     0,    98,     0,    99,   100,     0,   101,
       0,     0,   102,     0,     0,     0,     0,     0,     0,   268,
       0,   103,    83,    84,    85,    86,     0,     0,     0,     0,
       0,     0,   104,     0,     0,   105,     0,     0,    87,    88,
      89,    90,    91,    92,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,     0,    97,
       0,    98,     0,    99,   100,     0,   101,     0,     0,   102,
     329,     0,     0,     0,     0,     0,     0,     0,   103,    83,
      84,    85,    86,     0,     0,     0,     0,     0,     0,   104,
       0,     0,   105,     0,     0,    87,    88,    89,    90,    91,
      92,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,     0,    97,     0,    98,     0,
      99,   100,     0,   101,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,   103,    83,    84,    85,    86,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   105,
       0,     0,    87,    88,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,     0,    97,     0,    98,     0,    99,   100,     0,
     101,     0,     0,   158,     0,     0,     0,     0,     0,     0,
       0,     0,   103,    83,    84,    85,    86,     0,     0,     0,
       0,     0,     0,   104,     0,     0,   105,     0,     0,    87,
      88,    89,    90,    91,    92,    93,    94,     0,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,     0,
      97,     0,    98,     0,    99,   100,     0,   101,     0,     0,
     160,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     174,     0,     0,     0,     0,     0,     0,   175,   176,   177,
     104,     0,   254,   105,     0,     0,     0,     0,   199,   179,
       0,   180,   181,   182,     0,     0,   200,   201,   185,   186,
     187,   174,   188,   189,     0,     0,     0,     0,   175,   176,
     177,     0,     0,   254,   317,     0,     0,     0,     0,   178,
     179,     0,   180,   181,   182,     0,     0,   183,   184,   185,
     186,   187,   174,   188,   189,     0,     0,     0,     0,   175,
     176,   177,     0,     0,   254,   320,     0,     0,     0,     0,
     178,   179,     0,   180,   181,   182,     0,     0,   183,   184,
     185,   186,   187,   174,   188,   189,     0,     0,     0,     0,
     175,   176,   177,     0,     0,     0,     0,   244,     0,     0,
       0,   178,   179,     0,   180,   181,   182,     0,     0,   183,
     184,   185,   186,   187,   174,   188,   189,     0,     0,     0,
       0,   175,   176,   177,     0,     0,     0,     0,   246,     0,
       0,     0,   178,   179,     0,   180,   181,   182,     0,     0,
     183,   184,   185,   186,   187,   174,   188,   189,     0,     0,
       0,     0,   175,   176,   177,     0,     0,     0,     0,   249,
       0,     0,     0,   178,   179,     0,   180,   181,   182,     0,
       0,   183,   184,   185,   186,   187,   174,   188,   189,     0,
       0,     0,     0,   175,   176,   177,     0,     0,   254,     0,
       0,     0,     0,     0,   178,   179,     0,   180,   181,   182,
       0,     0,   183,   184,   185,   186,   187,   174,   188,   189,
       0,     0,     0,     0,   175,   176,   177,     0,     0,   312,
       0,     0,     0,     0,     0,   178,   179,     0,   180,   181,
     182,     0,     0,   183,   184,   185,   186,   187,   174,   188,
     189,     0,     0,     0,     0,   175,   176,   177,     0,     0,
       0,   313,     0,     0,     0,     0,   178,   179,     0,   180,
     181,   182,     0,     0,   183,   184,   185,   186,   187,   174,
     188,   189,     0,     0,     0,     0,   175,   176,   177,     0,
       0,   314,     0,     0,     0,     0,     0,   178,   179,     0,
     180,   181,   182,     0,     0,   183,   184,   185,   186,   187,
     174,   188,   189,     0,     0,     0,     0,   175,   176,   177,
       0,     0,   315,     0,     0,     0,     0,     0,   178,   179,
       0,   180,   181,   182,     0,     0,   183,   184,   185,   186,
     187,   174,   188,   189,     0,     0,     0,     0,   175,   176,
     177,     0,     0,     0,   316,     0,     0,     0,     0,   178,
     179,     0,   180,   181,   182,     0,     0,   183,   184,   185,
     186,   187,   174,   188,   189,     0,     0,     0,     0,   175,
     176,   177,     0,     0,   326,     0,     0,     0,     0,     0,
     178,   179,     0,   180,   181,   182,     0,     0,   183,   184,
     185,   186,   187,   174,   188,   189,     0,     0,     0,     0,
     175,   176,   177,     0,     0,   327,     0,     0,     0,     0,
       0,   178,   179,     0,   180,   181,   182,     0,     0,   183,
     184,   185,   186,   187,   174,   188,   189,     0,     0,     0,
       0,   175,   176,   177,     0,     0,     0,     0,   335,     0,
       0,     0,   178,   179,     0,   180,   181,   182,     0,     0,
     183,   184,   185,   186,   187,   174,   188,   189,     0,     0,
       0,     0,   175,   176,   177,     0,     0,     0,   336,     0,
       0,     0,     0,   178,   179,     0,   180,   181,   182,     0,
       0,   183,   184,   185,   186,   187,   174,   188,   189,     0,
       0,     0,     0,   175,   176,   177,     0,     0,     0,   337,
       0,     0,     0,     0,   178,   179,     0,   180,   181,   182,
       0,     0,   183,   184,   185,   186,   187,   174,   188,   189,
       0,     0,     0,     0,   175,   176,   177,  -124,     0,     0,
       0,     0,     0,     0,     0,   178,   179,     0,   180,   181,
     182,     0,     0,   183,   184,   185,   186,   187,   174,   188,
     189,     0,     0,     0,     0,   175,   176,   177,  -126,     0,
       0,     0,     0,     0,     0,     0,   178,   179,     0,   180,
     181,   182,     0,     0,   183,   184,   185,   186,   187,   174,
     188,   189,     0,     0,     0,     0,   175,   176,   177,  -128,
       0,     0,     0,     0,     0,     0,     0,   178,   179,     0,
     180,   181,   182,     0,     0,   183,   184,   185,   186,   187,
     174,   188,   189,     0,     0,     0,     0,   175,   176,   177,
       0,     0,   382,     0,     0,     0,     0,     0,   178,   179,
       0,   180,   181,   182,     0,     0,   183,   184,   185,   186,
     187,   174,   188,   189,     0,     0,     0,     0,   175,   176,
     177,     0,     0,     0,   383,     0,     0,     0,     0,   178,
     179,     0,   180,   181,   182,     0,     0,   183,   184,   185,
     186,   187,   174,   188,   189,     0,     0,     0,     0,   175,
     176,   177,     0,     0,   384,     0,     0,     0,     0,     0,
     178,   179,     0,   180,   181,   182,     0,     0,   183,   184,
     185,   186,   187,   174,   188,   189,     0,     0,     0,     0,
     175,   176,   177,     0,     0,   386,     0,     0,     0,     0,
       0,   178,   179,     0,   180,   181,   182,     0,     0,   183,
     184,   185,   186,   187,   174,   188,   189,     0,     0,     0,
       0,   175,   176,   177,     0,     0,   390,     0,     0,     0,
       0,     0,   178,   179,     0,   180,   181,   182,     0,     0,
     183,   184,   185,   186,   187,   174,   188,   189,     0,     0,
       0,     0,   175,   176,   177,     0,     0,   391,     0,     0,
       0,     0,     0,   178,   179,     0,   180,   181,   182,     0,
       0,   183,   184,   185,   186,   187,   174,   188,   189,     0,
       0,     0,     0,   175,   176,   177,     0,     0,   399,     0,
       0,     0,     0,     0,   178,   179,     0,   180,   181,   182,
       0,     0,   183,   184,   185,   186,   187,   174,   188,   189,
       0,     0,     0,     0,   175,   176,   177,     0,     0,     0,
     411,     0,     0,     0,     0,   178,   179,     0,   180,   181,
     182,     0,     0,   183,   184,   185,   186,   187,   174,   188,
     189,     0,     0,     0,     0,   175,   176,   177,     0,     0,
     419,     0,     0,     0,     0,     0,   178,   179,     0,   180,
     181,   182,     0,     0,   183,   184,   185,   186,   187,   174,
     188,   189,     0,     0,     0,     0,   175,   176,   177,     0,
       0,     0,   421,     0,     0,     0,     0,   178,   179,     0,
     180,   181,   182,     0,     0,   183,   184,   185,   186,   187,
     174,   188,   189,     0,     0,     0,     0,   175,   176,   177,
       0,     0,   425,     0,     0,     0,     0,     0,   178,   179,
       0,   180,   181,   182,     0,     0,   183,   184,   185,   186,
     187,   174,   188,   189,     0,     0,     0,     0,   175,   176,
     177,     0,     0,     0,     0,     0,     0,     0,     0,   178,
     179,     0,   180,   181,   182,     0,     0,   183,   184,   185,
     186,   187,     0,   188,   189,   175,   176,   177,     0,     0,
       0,     0,     0,     0,     0,     0,   178,   179,     0,   180,
     181,   182,     0,     0,   183,   184,   185,   186,   187,     0,
     188,   175,   176,   177,     0,     0,     0,     0,     0,     0,
       0,     0,   178,   179,     0,   180,   181,   182,     0,     0,
     183,   184,   185,   186,   187,   175,   176,   177,     0,     0,
       0,     0,     0,     0,     0,     0,   178,   179,     0,   180,
     181,   182,     0,     0,   183,   184,   185,     0,   187,   175,
     176,   177,     0,     0,     0,     0,     0,     0,     0,     0,
     178,   179,     0,   180,   181,   182,     0,     0,   183,   184,
     185,   175,   176,   177,     0,     0,     0,     0,     0,     0,
       0,     0,   178,   179,     0,   180,   181,   182,     0,     0,
     183,   184
  };

  const short int
  parser::yycheck_[] =
  {
      59,   116,   247,   223,     2,   218,     5,    11,    12,    13,
       5,     5,     5,     5,    67,    68,     5,     7,    31,     5,
     233,    12,    13,   236,     4,     5,    62,     4,     5,    82,
      62,    63,    91,    92,    61,    94,    60,    64,    62,    98,
      76,    73,   101,   102,    58,   104,   105,    27,    28,    62,
      27,    28,     4,    67,    54,     0,    62,    71,   117,    62,
      60,    75,    76,     5,    53,    63,    52,    61,    74,    29,
      30,    74,    76,   318,    73,    58,   321,   297,    73,   324,
      73,    73,    72,     5,    67,    76,     5,   202,    61,    62,
     303,    53,    75,    76,   153,   154,   155,   156,   157,   158,
      62,   160,    53,    60,    60,   164,   165,    60,    65,    65,
       5,    62,    65,    61,    62,     5,   175,   176,     5,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   130,   192,   193,   194,   349,    58,     5,   198,
     199,   200,   201,    61,    62,     5,    67,    68,     5,    70,
      71,    72,    61,    62,    75,    76,    61,    62,     5,     3,
       4,     5,     6,     5,   162,    65,     4,   380,    75,    60,
      62,    60,    75,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    67,    67,    67,     5,     5,
       5,    76,     6,     8,   253,     5,   255,     5,     5,    73,
       5,   260,    60,    47,    48,    60,    50,   266,    52,   268,
      54,    55,    60,    57,    58,    60,    60,    32,    33,    34,
      35,    36,    37,    38,    39,    69,    41,    42,    43,    44,
      45,    46,    60,    63,    60,    60,    80,     5,    59,    83,
      60,    60,    64,    67,    62,    84,   244,     5,   246,    51,
      62,   249,    65,    62,   313,     6,    62,   316,   317,    63,
      63,   320,     5,    63,     3,     4,     5,     6,     9,    10,
      11,    12,    13,    14,    15,    16,   335,   336,   337,    61,
      19,    20,    21,    22,    23,    24,    25,    26,    67,    32,
      65,    60,     5,    67,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    60,     5,     5,   366,    47,    48,
      60,    50,     5,    52,    53,    54,    55,     5,    57,    63,
       6,    60,     7,     5,   383,    63,     5,     5,    63,    63,
      69,    74,     5,    61,    67,     5,    84,    74,    62,     5,
      63,    80,    63,    74,    83,   404,     6,    74,    74,     5,
       5,    62,   411,    73,   413,     5,    62,   416,     3,     4,
       5,     6,   421,   422,    49,    84,    60,   426,     5,    84,
      62,    56,    57,    58,    19,    20,    21,    22,    23,    24,
      25,    26,    67,    68,     5,    70,    71,    72,   130,    66,
      75,    76,    77,    78,    79,    66,    81,    82,    61,    66,
     130,   224,    47,    48,   203,    50,   340,    52,   130,    54,
      55,    -1,    57,   130,   130,    60,   117,    -1,   130,    -1,
     130,   130,    67,    -1,    69,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    50,    -1,    52,    -1,    54,    55,    -1,    57,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    69,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,
      -1,    52,    -1,    54,    55,    -1,    57,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    83,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    50,    -1,    52,    -1,
      54,    55,    -1,    57,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    50,    -1,    52,    -1,    54,    55,    -1,
      57,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      50,    -1,    52,    -1,    54,    55,    -1,    57,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      80,    -1,    61,    83,    -1,    -1,    -1,    -1,    67,    68,
      -1,    70,    71,    72,    -1,    -1,    75,    76,    77,    78,
      79,    49,    81,    82,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    70,    71,    72,    -1,    -1,    75,    76,    77,
      78,    79,    49,    81,    82,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    -1,    70,    71,    72,    -1,    -1,    75,    76,
      77,    78,    79,    49,    81,    82,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    67,    68,    -1,    70,    71,    72,    -1,    -1,    75,
      76,    77,    78,    79,    49,    81,    82,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    67,    68,    -1,    70,    71,    72,    -1,    -1,
      75,    76,    77,    78,    79,    49,    81,    82,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    67,    68,    -1,    70,    71,    72,    -1,
      -1,    75,    76,    77,    78,    79,    49,    81,    82,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    70,    71,    72,
      -1,    -1,    75,    76,    77,    78,    79,    49,    81,    82,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,    71,
      72,    -1,    -1,    75,    76,    77,    78,    79,    49,    81,
      82,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,
      71,    72,    -1,    -1,    75,    76,    77,    78,    79,    49,
      81,    82,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      70,    71,    72,    -1,    -1,    75,    76,    77,    78,    79,
      49,    81,    82,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    70,    71,    72,    -1,    -1,    75,    76,    77,    78,
      79,    49,    81,    82,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    70,    71,    72,    -1,    -1,    75,    76,    77,
      78,    79,    49,    81,    82,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    70,    71,    72,    -1,    -1,    75,    76,
      77,    78,    79,    49,    81,    82,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    -1,    70,    71,    72,    -1,    -1,    75,
      76,    77,    78,    79,    49,    81,    82,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    67,    68,    -1,    70,    71,    72,    -1,    -1,
      75,    76,    77,    78,    79,    49,    81,    82,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    70,    71,    72,    -1,
      -1,    75,    76,    77,    78,    79,    49,    81,    82,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    67,    68,    -1,    70,    71,    72,
      -1,    -1,    75,    76,    77,    78,    79,    49,    81,    82,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,    71,
      72,    -1,    -1,    75,    76,    77,    78,    79,    49,    81,
      82,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,
      71,    72,    -1,    -1,    75,    76,    77,    78,    79,    49,
      81,    82,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      70,    71,    72,    -1,    -1,    75,    76,    77,    78,    79,
      49,    81,    82,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    70,    71,    72,    -1,    -1,    75,    76,    77,    78,
      79,    49,    81,    82,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    70,    71,    72,    -1,    -1,    75,    76,    77,
      78,    79,    49,    81,    82,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    70,    71,    72,    -1,    -1,    75,    76,
      77,    78,    79,    49,    81,    82,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    -1,    70,    71,    72,    -1,    -1,    75,
      76,    77,    78,    79,    49,    81,    82,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    -1,    70,    71,    72,    -1,    -1,
      75,    76,    77,    78,    79,    49,    81,    82,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    70,    71,    72,    -1,
      -1,    75,    76,    77,    78,    79,    49,    81,    82,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    70,    71,    72,
      -1,    -1,    75,    76,    77,    78,    79,    49,    81,    82,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,    71,
      72,    -1,    -1,    75,    76,    77,    78,    79,    49,    81,
      82,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,
      71,    72,    -1,    -1,    75,    76,    77,    78,    79,    49,
      81,    82,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      70,    71,    72,    -1,    -1,    75,    76,    77,    78,    79,
      49,    81,    82,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    70,    71,    72,    -1,    -1,    75,    76,    77,    78,
      79,    49,    81,    82,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    70,    71,    72,    -1,    -1,    75,    76,    77,
      78,    79,    -1,    81,    82,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,
      71,    72,    -1,    -1,    75,    76,    77,    78,    79,    -1,
      81,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    -1,    70,    71,    72,    -1,    -1,
      75,    76,    77,    78,    79,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,
      71,    72,    -1,    -1,    75,    76,    77,    -1,    79,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    70,    71,    72,    -1,    -1,    75,    76,
      77,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    -1,    70,    71,    72,    -1,    -1,
      75,    76
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    87,    88,     0,     5,     8,    32,    33,    34,    35,
      36,    37,    38,    39,    41,    42,    43,    44,    45,    46,
      89,    91,    95,    99,   102,   105,   106,   107,   111,   112,
     122,   124,   125,   134,   135,   139,   141,   142,     4,     5,
     103,   104,   103,     5,     5,     5,     5,    95,   113,   114,
     113,   113,     5,     5,     5,   138,     5,     5,     5,    60,
      65,    65,    31,    62,    29,    30,   133,    62,    63,    73,
       4,    60,    62,    75,    60,    60,    62,    60,    67,    67,
      75,   137,    67,     3,     4,     5,     6,    19,    20,    21,
      22,    23,    24,    25,    26,    47,    48,    50,    52,    54,
      55,    57,    60,    69,    80,    83,   115,   116,   120,   121,
       5,     5,    17,    18,    27,    28,    58,    60,   115,   122,
     123,   126,   127,   128,   129,   122,     6,   132,   138,   138,
     140,     5,    96,    97,   103,    76,     5,     5,    61,   100,
     101,   113,     5,   109,   110,     5,    52,    90,    93,    73,
       5,   136,   138,    60,    60,    60,    60,    60,    60,   115,
      60,   115,    63,   115,    60,    60,    53,   115,   119,   115,
     115,     5,   115,   115,    49,    56,    57,    58,    67,    68,
      70,    71,    72,    75,    76,    77,    78,    79,    81,    82,
      59,    61,    62,    60,    60,   126,   115,   128,     7,    67,
      75,    76,    62,    64,    65,    63,    62,    40,    74,    91,
     102,   111,   112,   124,   135,   141,   142,   143,    63,    61,
      62,    67,    62,    63,    62,    61,    67,    61,    62,     5,
      53,    92,    65,    51,    84,    94,    62,    76,   115,   115,
     115,   115,   115,   115,    63,   115,    63,    73,   122,    63,
     115,   115,    53,    62,    61,    60,   117,     5,   115,   115,
      67,   115,   115,   115,   115,   115,    67,   115,    67,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,    61,
     115,   115,   115,   115,   126,   127,    60,   131,     6,     5,
      90,    98,     5,    60,     5,   100,   101,    63,     4,     5,
      27,    28,     5,    63,    53,    62,     5,    90,     5,    62,
      74,    90,    61,    62,    61,    61,    62,    62,    73,   122,
      62,    73,   122,   129,    73,   122,    61,    61,   115,    61,
     115,   118,   115,   115,   115,    63,    62,    62,     6,   130,
      63,     9,    10,    11,    12,    13,    14,    15,    16,    63,
       5,    61,   100,    67,    90,     5,    84,   115,   115,   115,
     129,   115,   129,    74,   129,    61,    62,   115,   115,   115,
      61,    62,   131,    90,    62,    63,     4,     5,    27,    28,
      63,     5,    61,    62,    61,    74,    61,    74,    74,   115,
      61,    61,     6,     5,     5,    90,   115,    62,    73,    61,
       5,    84,   108,    62,    60,    62,    74,     5,   115,    84,
      62,    62,    54,    60,     5,   115,    66,   115,    61,    61,
     115,    62,    66,   115,   115,    61,    66,   115
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    86,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    90,
      90,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    99,
      99,   100,   101,   101,   102,   103,   103,   104,   105,   106,
     107,   108,   108,   108,   109,   109,   109,   109,   109,   109,
     109,   109,   110,   110,   111,   112,   112,   113,   113,   114,
     114,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   116,   116,   116,   116,
     117,   117,   118,   118,   119,   119,   120,   120,   121,   121,
     122,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     124,   125,   125,   126,   126,   126,   127,   127,   128,   128,
     129,   130,   130,   131,   132,   132,   133,   134,   135,   135,
     135,   136,   136,   137,   137,   138,   139,   139,   139,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   141,
     142,   143
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     0,     3,     2,     1,
       3,     2,     2,     2,     4,     6,     5,     6,     3,     5,
       1,     3,     2,     4,     1,     3,     3,     5,     1,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     7,
       6,     1,     3,     1,     2,     1,     3,     5,     2,    16,
      12,     8,    10,     6,     3,     5,     3,     5,     3,     5,
       3,     5,     1,     0,     2,     2,     2,     1,     3,     4,
       1,     1,     1,     1,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     6,
       6,     6,     4,     4,     4,     4,     8,     5,     3,     2,
       2,     2,     2,     3,     1,     3,     5,     4,     6,     4,
       6,     4,     6,     4,     3,     4,     3,     4,     3,     4,
       2,     3,     1,     3,     1,     3,     1,     3,     1,     0,
       4,     3,     3,     3,     3,     1,     6,     6,     1,     1,
       2,     1,     3,     1,     2,     3,     1,     3,     1,     3,
       1,     1,     3,     3,     3,     5,     2,     4,     1,     2,
       2,     1,     3,     0,     3,     2,     2,     3,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     4,
       4,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"reserved keyword\"",
  "\"symbol\"", "\"identifier\"", "\"number\"", "\"relational operator\"",
  "\"pragma directive\"", "\"relation qualifier output\"",
  "\"relation qualifier input\"", "\"relation qualifier printsize\"",
  "\"BRIE datastructure qualifier\"", "\"BTREE datastructure qualifier\"",
  "\"equivalence relation qualifier\"",
  "\"relation qualifier overidable\"", "\"relation qualifier inline\"",
  "\"match predicate\"",
  "\"checks whether substring is contained in a string\"",
  "\"concatenation of two strings\"", "\"ordinal number of a string\"",
  "\"length of a string\"", "\"sub-string of a string\"",
  "\"min aggregator\"", "\"max aggregator\"", "\"count aggregator\"",
  "\"sum aggregator\"", "\"true literal constraint\"",
  "\"false literal constraint\"", "\"strict marker\"", "\"plan keyword\"",
  "\":-\"", "\"relation declaration\"", "\"lattice declaration\"",
  "\"lattice components type declaration\"",
  "\"lattice binary function definition\"", "\"functor declaration\"",
  "\"input directives declaration\"", "\"output directives declaration\"",
  "\"printsize directives declaration\"",
  "\"override rules of super-component\"", "\"type declaration\"",
  "\"enum declaration\"", "\"component declaration\"",
  "\"component instantiation\"", "\"numeric type declaration\"",
  "\"symbolic type declaration\"", "\"convert string to number\"",
  "\"convert number to string\"", "\"type cast\"", "\"nil reference\"",
  "\"|\"", "\"[\"", "\"]\"", "\"_\"", "\"$\"", "\"+\"", "\"-\"", "\"!\"",
  "\"?\"", "\"(\"", "\")\"", "\",\"", "\":\"", "\";\"", "\".\"", "\"=>\"",
  "\"=\"", "\"*\"", "\"@\"", "\"/\"", "\"^\"", "\"%\"", "\"{\"", "\"}\"",
  "\"<\"", "\">\"", "\"band\"", "\"bor\"", "\"bxor\"", "\"bnot\"",
  "\"land\"", "\"lor\"", "\"lnot\"", "\"case\"", "NEG", "$accept",
  "program", "unit", "pragma", "type_id", "type", "recordtype",
  "uniontype", "enumtype", "rel_id", "non_empty_attributes", "attributes",
  "qualifiers", "functor_decl", "functor_type", "functor_typeargs",
  "relation_decl", "relation_list", "relation_body", "lattice_decl",
  "lattice_asscoiation", "lattice_def", "lattice_def_type",
  "non_empty_key_value_pairs", "key_value_pairs", "load_head",
  "store_head", "iodirective_list", "iodirective_body", "arg", "condition",
  "functor_list", "functor_args", "recordlist", "non_empty_arg_list",
  "arg_list", "atom", "literal", "fact", "head", "term", "conjunction",
  "disjunction", "body", "exec_order_list", "exec_order", "exec_plan_list",
  "exec_plan", "rule_def", "rule", "type_param_list", "type_params",
  "comp_type", "component_head", "component_body", "component",
  "comp_init", "comp_override", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   241,   241,   245,   248,   251,   254,   258,   262,   266,
     269,   272,   275,   278,   281,   284,   287,   292,   297,   306,
     309,   316,   320,   324,   328,   333,   338,   343,   351,   355,
     361,   365,   371,   377,   388,   391,   399,   406,   415,   418,
     423,   427,   431,   435,   439,   443,   447,   451,   455,   460,
     464,   471,   481,   482,   486,   491,   494,   503,   511,   519,
     525,   536,   540,   544,   551,   555,   559,   563,   567,   571,
     575,   579,   585,   588,   594,   601,   607,   615,   618,   627,
     633,   642,   646,   650,   654,   659,   663,   667,   670,   674,
     678,   682,   686,   690,   694,   698,   702,   706,   710,   714,
     718,   722,   726,   730,   734,   738,   742,   749,   753,   757,
     768,   772,   776,   780,   784,   788,   794,   809,   816,   832,
     839,   855,   862,   878,   884,   888,   892,   896,   900,   904,
     912,   915,   921,   925,   932,   936,   942,   946,   952,   955,
     960,   969,   974,   979,   984,   989,   993,   998,  1003,  1008,
    1016,  1024,  1027,  1034,  1037,  1041,  1047,  1050,  1058,  1061,
    1069,  1074,  1078,  1085,  1092,  1096,  1103,  1110,  1132,  1135,
    1139,  1147,  1150,  1157,  1159,  1166,  1173,  1177,  1181,  1187,
    1191,  1195,  1199,  1203,  1207,  1213,  1217,  1221,  1225,  1230,
    1240,  1249
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 4200 "parser.cc" // lalr1.cc:1167
#line 1253 "./parser.yy" // lalr1.cc:1168

void yy::parser::error(const location_type &l, const std::string &m) {
    driver.error(l, m);
}
