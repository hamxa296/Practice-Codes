import streamlit as st

def grade_to_points(grade):
    grade_points = {
        "A": 4.0,
        "A-": 3.67,
        "B+": 3.3,
        "B": 3.0,
        "B-": 2.7,
        "C+": 2.3,
        "C": 2.0,
        "C-": 1.7,
        "D+": 1.3,
        "D": 1.0,
        "F": 0.0
    }
    return grade_points.get(grade, -1)

def main():
    st.title("GPA Calculator")
    st.subheader("Enter your grades for each course:")
    
    courses = {
        "HM Lab": 1,
        "HM Theory": 2,
        "IF Lab": 1,
        "CS Lab": 1,
        "CS Theory": 2,
        "Chem": 2,
        "OHS": 1,
        "MT": 3,
        "ES": 3,
        "AI": 1
    }
    
    grades = {}
    for course, credits in courses.items():
        grades[course] = st.selectbox(
            f"{course} ({credits} CH):",
            ["A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "F"],
            key=course
        )
    
    if st.button("Calculate GPA"):
        total_points = 0
        total_credits = sum(courses.values())
        
        for course, credits in courses.items():
            points = grade_to_points(grades[course])
            if points == -1:
                st.error(f"Invalid grade entered for {course}. Use A, A-, B+, B, B-, C+, C, C-, D+, D, or F.")
                return
            total_points += points * credits
        
        if total_credits == 0:
            st.error("Error: Total credit hours cannot be zero.")
            return
        
        sgpa = total_points / total_credits
        st.success(f"Your SGPA for this semester is: {sgpa:.3f}")
        
        # Store SGPA in session state
        st.session_state.sgpa = sgpa
        st.session_state.total_credits = total_credits

    # CGPA Projection section
    st.subheader("CGPA Projection")
    col1, col2 = st.columns(2)
    with col1:
        current_cgpa = st.number_input("Enter your current CGPA:", min_value=0.0, max_value=4.0, step=0.01)
    with col2:
        completed_credits = st.number_input("Enter total completed credit hours before this semester:", min_value=0, step=1)
    
    if st.button("Calculate CGPA Projection"):
        if 'sgpa' not in st.session_state:
            st.error("Please calculate your SGPA first!")
            return
            
        sgpa = st.session_state.sgpa
        total_credits = st.session_state.total_credits
        
        if current_cgpa > 0 and completed_credits > 0:
            new_cgpa = ((current_cgpa * completed_credits) + (sgpa * total_credits)) / (completed_credits + total_credits)
            st.info(f"Your projected new CGPA will be: {new_cgpa:.3f}")
            
            # Calculate required SGPA to reach goal
            st.subheader("Goal Calculator")
            goal_cgpa = st.number_input("Enter your target CGPA:", min_value=0.0, max_value=4.0, step=0.01)
            
            if goal_cgpa > 0:
                required_sgpa = ((goal_cgpa * (completed_credits + total_credits)) - (current_cgpa * completed_credits)) / total_credits
                if required_sgpa <= 4.0:
                    st.warning(f"To reach a CGPA of {goal_cgpa:.2f}, you need an SGPA of {required_sgpa:.3f} this semester.")
                else:
                    st.error("It's not possible to reach this CGPA in one semester (required SGPA exceeds 4.0).")

if __name__ == "__main__":
    main()