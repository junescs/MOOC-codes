#Some coding practices from the course "introduction to Python" at Udacity

#lambda practice 1
#using lambda expression to calculate the average of the lists in numbers
#map()- takes a function and iterable as inputs, 
#and returns an iterator that applies the function to each element of the iterable
numbers = [
              [34, 63, 88, 71, 29],
              [90, 78, 51, 27, 45],
              [63, 37, 85, 46, 22],
              [51, 22, 34, 11, 18]
           ]

averages = list(map(lambda x: sum(x) / len(x), numbers))
print(averages)

#get the same result as below:
#def mean(num_list):
#    return sum(num_list) / len(num_list)

#averages = list(map(mean, numbers))


#lambda practice 2
#filter the city name lengthed less than 10 characters
#filter()-takes a function and iterable as inputs, 
#and returns an iterator with the elements from the iterable for which the function returns True. 
cities = ["New York City", "Los Angeles", "Chicago", "Mountain View", "Denver", "Boston"]

short_cities = list(filter(lambda x: len(x) < 10, cities))
print(short_cities)

#get the same result as below:
#def is_short(name):
#    return len(name) < 10

#short_cities = list(filter(is_short, cities))
