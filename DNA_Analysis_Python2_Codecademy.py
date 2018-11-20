# This is the coding practice from section 12 of Learn Python 2 in Codecademy, 
# analysing the given DNA files with the sample codons in order to find out the wanted suspect,
# then display the matching result.

sample = ['GTA','GGG','CAC']

#to read the file
def read_dna(dna_file):
  dna_data = ""
  with open(dna_file, "r") as f:
    for line in f:
      dna_data += line 
  return dna_data

#to chop the dna into codons
def dna_codons(dna):
  codons = []
  for x in range(0, len(dna), 3):
    #make sure it is a 3-letter codon
    if (x + 3) < len(dna):
      codons.append(dna[x:x+3])
  return codons

#to check through the dna
def match_dna(dna):
  matches = 0
  for codon in dna:
    if codon in sample:
      matches += 1
  return matches

#to find out who's codons it is
def is_criminal(dna_sample):
  #read the dna sample and record it
  dna_data = read_dna(dna_sample)
  #chop the dna 
  codons = dna_codons(dna_data)
  #match the sample with chopped codons
  num_matches = match_dna(codons)
  #3 arguments in the sample list
  if num_matches >= 3:
    print "%s codons of DNA are matched. The investigation should continue." % num_matches
  else:
    print "Only %s codons of DNA are matched. The suspect can be freed." % num_matches
    
#run through all the suspects' file
is_criminal('suspect1.txt')
is_criminal('suspect2.txt')
is_criminal('suspect3.txt')
