lefty="({["
righty=")}]"


# Function to check parentheses
def checker(expr):
    stack = []
    for i in expr:
        if i in lefty:
            stack.append(i)
        elif i in righty:
            pos = righty.index(i)
            if ((len(stack) > 0) and
                    (lefty[pos] == stack[len(stack) - 1])):
                stack.pop()
            else:
                return "Unbalanced"
    if len(stack) == 0:
        return "Balanced"
    else:
        return "Unbalanced"

#driver code
str=input("enter the expresssion :")
print(checker(str))