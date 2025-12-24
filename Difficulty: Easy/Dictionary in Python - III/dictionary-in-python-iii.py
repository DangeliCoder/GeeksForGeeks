# insert into dictionary
def insert_dict(query, dict):
    
    # Your code here
    dict[query[1]] = query[2]

    

# deleting from dictionary
def del_dict(query, dict):
    
    # Your code here
    if query[1] in dict:
        del dict[query[1]]
    else:
        print(-1)

    
    
    

# print marks of required name
def print_dict(key, dict):
    
    # Your code here
    if key in dict:
        print(f"Marks of {key} is", dict[key])
    else:
        print(-1)

    
    