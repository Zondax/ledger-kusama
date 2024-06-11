import json
import os

def extract_blobs(json_file, initial_corpus_dir):
    # Load the JSON file containing the test cases
    with open(json_file, 'r') as file:
        test_cases = json.load(file)

    # Write the 'blob' field of each test case to a separate file in the initial_corpus_dir
    for i, test_case in enumerate(test_cases):
        blob_content = test_case.get('blob', '')  # Get the 'blob' field or default to empty string if not found
        if blob_content:  # Only write out if blob_content is not empty
            case_path = os.path.join(initial_corpus_dir, f'blob_{i}.txt')
            with open(case_path, 'w') as case_file:
                case_file.write(blob_content)

# Ensure the initial_corpus_dir is created
initial_corpus_dir = os.path.join('fuzz', 'corpora', 'initial_corpus')
os.makedirs(initial_corpus_dir, exist_ok=True)

# Process both current and previous test cases
extract_blobs('tests/testcases_current.json', initial_corpus_dir)
extract_blobs('tests/testcases_previous.json', initial_corpus_dir)
