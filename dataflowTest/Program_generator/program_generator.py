import numpy as np
import random

VarMap='abcdefghijklmnopqrstuvwxyz'

class Program :
	# pi is probability of a statement , p0 : x=c , p1 : x=y+z ,
	# p2 : x=y−z , p3 : x=y*z , p4 : x=y / z
	# p5 : if [cond] then S1 else S2 , p6 : while [cond] do S
	def __init__ ( self , seed , prob , totVar , minLines ) :
		for p in prob :
			assert p>=0
		assert abs(sum(prob) - 1.0) < 1e-6

		self.totVar = totVar
		assert self.totVar > 0
		assert self.totVar < 1000 # sizeof VarMap

		self.minLines = minLines
		# Must have more l i n e s than i n i t i a l i z a t i o n o f v a r i a b l e s
		assert self.minLines> self.totVar

		self.curLine= 0

		self.thres =[sum( prob [ : i +1]) for i in range (len ( prob ) ) ]
		
		self.setFacts = [ ] # x=c
		self.AddFacts = [ ] # x=y+z
		self.MinusFacts = [ ] # x=y−z
		self.MultFacts = [ ] # x=y∗ z
		self.DivFacts = [ ] # x=y / z
		self.Flow = [ ] # c o n t r o l f l o w from l 1 t o l 2

		self.Code = " " # Code o f t h e program

		self.seed = seed
		return

	# i n i t i a l i z e a l l v a r i a b l e s in t h e g e n e r a t e d program
	def initVars (self):
		for i in range (self.totVar):
			random.seed (self.seed )
			self.increSeed( )
			value = random . randint(-2, 2 )

			self.setFacts.append((i, VarMap[i], value ))
			self.insertLineWithLable(VarMap[i] + "=" + str(value), 0)
			self.addFlow ( ( i , i +1) )
			self.increLine() # start a new line

	def increLine (self):
		self.curLine += 1
		self.Code += "\n"
		return

	# randomly s e l e c t 3 v a r i a b l e s and pu t in a t u p l e
	def randThreeVars (self) :
		random.seed(self.seed)
		self.increSeed( )
		s1 = VarMap [random.randint(0, self.totVar -1) ]
		random.seed(self.seed)
		self.increSeed( )
		s2 = VarMap [random.randint(0, self.totVar -1) ]
		random.seed(self.seed)
		self.increSeed( )
		s3 = VarMap [random.randint(0, self.totVar -1) ]
		return ( s1 , s2 , s3 )

	def addSet(self, level):
		random.seed(self.seed)
		self.increSeed( )
		varInd = random.randint(0, self.totVar -1)

		random.seed(self.seed)
		value = random.randint(-2, 2) # −20 , 20
		
		self.setFacts.append((self.curLine, VarMap[varInd], value))
		self.insertLineWithLable (VarMap[varInd] + "=" + str(value), level)
		return

	def addAdd(self, level):
		varTuple = self.randThreeVars ( )
		t = (self.curLine, ) + varTuple
		self.AddFacts.append(t)
		self.insertLineWithLable(varTuple [0]+ "="+varTuple [ 1 ] + "+" + varTuple[2] , level)
		return

	def addMinus(self, level):
		varTuple = self.randThreeVars( )
		t = (self.curLine, ) + varTuple
		self.MinusFacts.append(t)
		self.insertLineWithLable(varTuple[0] + "=" + varTuple[1] + "−" + varTuple [ 2 ], level)
		return

	def addMult (self, level):
		varTuple = self.randThreeVars( )
		t = (self.curLine, ) + varTuple
		self.MultFacts.append(t)
		self.insertLineWithLable(varTuple[0] + "=" + varTuple[1] + "*" + varTuple [ 2 ], level)
		return

	def addDiv (self, level):
		varTuple = self.randThreeVars( )
		t = (self.curLine, ) + varTuple
		self.DivFacts.append(t)
		self.insertLineWithLable(varTuple[0] + "=" + varTuple[1] + "/" + varTuple [ 2 ], level)
		return

	def addFlow (self, fl):
		self.Flow.append(fl)
		return

	def insertLineWithLable (self, string, level):
		self.Code += str(self.curLine)+ (5-len(str(self.curLine))) * " " + "\t" * level
		self.Code += string

	def insertLineWithoutLable (self, string, level):
		self.Code += " " * 5 + "\t" * level
		self.Code += string

	def increSeed(self):
		random.seed(self.seed)
		self.seed = random.randint(-9999999999, 9999999999)

	def printAll(self):
		print( "total number of Variables: " , self.totVar)
		print( "minimum lines: " , self.minLines)
		print( "current line: " , self.curLine)
		print( "setFacts : " , self.setFacts)
		print( "AddFacts : " , self.AddFacts)
		print( "MinusFacts : " , self.MinusFacts)
		print( "MultFacts : " , self.MultFacts)
		print( "DivFacts : " , self.DivFacts)
		print( "Flow : " , self.Flow)
		print( "Code :")
		print(self.Code)

	def makeFactFiles(self):
		f = open("facts/setConstStm.facts", "w")
		for elt in self.setFacts:
			f.write(str(elt[0]) + '\t' + elt[1] + '\t' + str(elt[2]) + '\n')
		f.close()
		f = open("facts/addStm.facts", "w")
		for elt in self.AddFacts:
			f.write(str(elt[0]) + '\t' + elt[1] + '\t' + elt[2] + '\t' + elt[3] + '\n')
		f.close()
		f = open("facts/minusStm.facts", "w")
		for elt in self.MinusFacts:
			f.write(str(elt[0]) + '\t' + elt[1] + '\t' + elt[2] + '\t' + elt[3] + '\n')
		f.close()
		f = open("facts/multStm.facts", "w")
		for elt in self.MultFacts:
			f.write(str(elt[0]) + '\t' + elt[1] + '\t' + elt[2] + '\t' + elt[3] + '\n')
		f.close()
		f = open("facts/divStm.facts", "w")
		for elt in self.DivFacts:
			f.write(str(elt[0]) + '\t' + elt[1] + '\t' + elt[2] + '\t' + elt[3] + '\n')
		f.close()
		f = open("facts/flow.facts", "w")
		for elt in self.AddFacts:
			f.write(str(elt[0]) + '\t' + str(elt[1]) + '\n')
		f.close()


		f = open("facts/varEntry.facts", "w")
		fact = self.setFacts[0]
		f.write(str(fact[0]) + '\t' + fact[1] + '\t' + "Bot" + '\n')
		f.close()

# t o tV a r : t o t a l number o f v a r i a b l e s
# minL : l e a s t l i n e s r e q u r i e d
# l e v e l : sc o pe l e v e l o f c u r r e n t s t a t em e n t
def buildIfElse( prog, minL, level):
	random.seed(prog.seed)
	prog.increSeed()
	S1_L = random.randint( 0, minL-2)
	S2_L = minL - 2 - S1_L

	if_label = prog.curLine
	prog.insertLineWithLable( "IF (condition):" , level)

	prog.increLine( )
	S1_start = prog.curLine
	if(S1_L!=0):
		count1 = buildStatement( prog, S1_L, level + 1)
	else:
		count1 = 1
		prog.insertLineWithLable("", level + 1)
	S1_end = prog.curLine

	prog.increLine()
	prog.insertLineWithoutLable("ELSE: \n", level)
	S2_start = prog.curLine
	if(S2_L != 0):
		count2 = buildStatement( prog, S2_L, level + 1)
	else:
		count2 = 1
		prog.insertLineWithLable("", level + 1)
	S2_end = prog.curLine

	# s t a r t a new l i n e
	prog.increLine( )
	prog.insertLineWithLable("End IF ", level)

	# c onnec t IF t o s t a r t s o f S1 and S2
	prog.addFlow((if_label, S1_start))
	prog.addFlow((if_label, S2_start))

	# c onnec t ends o f S1 and S2 t o new l i n e
	prog.addFlow((S1_end, prog.curLine))
	prog.addFlow((S2_end, prog.curLine))

	return 2+count1+count2

def buildWhile(prog, minL, level):

	while_label = prog.curLine
	prog.insertLineWithLable("While (condition):", level)

	prog.increLine()
	S_start = prog.curLine
	count = buildStatement(prog, minL-2, level + 1)
	S_end = prog.curLine
	
	# s t a r t a new l i n e
	prog.increLine()
	prog.insertLineWithLable("End While", level)
	
	prog.addFlow((while_label, S_start))
	prog.addFlow((S_end, while_label))

	prog.addFlow((while_label, prog.curLine))

	return 2+count

def buildStatement(prog, minL, level):
	count = 0
	while (count < minL):
		# p r i n t ( " coun t : " , coun t , " , minL : " , minL )
		random.seed(prog.seed)
		prog.increSeed()
		r = random.random()
		if ( r<prog.thres[0]):
			prog.addSet(level)

			count += 1
		elif (r<prog.thres[1]):
			prog.addAdd(level)
			count += 1
		elif (r<prog.thres[2]):
			prog.addMinus(level)
			count += 1
		elif (r<prog.thres[3]):
			prog.addMult(level)
			count += 1
		elif (r<prog.thres[4]):
			prog.addDiv(level)
			count += 1
		elif (r<prog.thres[5]):
			random.seed(prog.seed)
			prog.increSeed()
			n = random.randint(4, max(4, min(30, minL)))
			count += buildIfElse(prog, n, level)
		else:
			random.seed(prog.seed)
			prog.increSeed()
			n = random.randint(3, max(3, min(30, minL)))
			count += buildWhile(prog, n, level)

		# s t a r t a new l i n e
		if (count<minL) :
			prog.addFlow((prog.curLine, prog.curLine+1))
			prog.increLine()
			count+=buildStatement(prog, minL-count, level)

	return count


# p0 : x=c , p1 : x=y+z , p2 : x=y−z , p3 : x=y∗z , p4 : x=y / z
# p5 : i f [ cond ] t hen S1 e l s e S2 , p6 : w h i l e [ cond ] do S
# N o t ice : t o t e s t no−l a t t i c e s o u f f l e , must p6 t o z e r o
myProg = Program(4837 , [ 0.2, 0.15, 0.15, 0.15, 0.15, 0.1, 0.1] , 5, 50)
myProg.initVars()
#while (myProg.curLine < myProg.minLines):
buildStatement(myProg, myProg.minLines - myProg.curLine, 0)
myProg.printAll()
myProg.makeFactFiles()