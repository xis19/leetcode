def get_importance(employees, id)
	employee = employees.find { |i| i.id == id }
  employee.importance + (employee.subordinates.map { |i| get_importance(employees, employees.find { |j| j.id == i }.id) }.reduce(:+) or 0)
end
