import os

def build_template(template, template_data):
    # Fetch template file
    template_path = './' + template + '.html'
    template_str = ''

    if os.path.exists(template_path):
        with open(template_path) as f:
            template_str = f.read()
            f.close()

    if len(template_data) != 0:

        for template_data_item in template_data:
            template_str = template_str.replace(template_data_item, template_data[template_data_item], -1)

    return template_str


template = build_template('template', {
    '{{title}}': 'Such title, very wow',
    '{{header}}': 'Very interesting',
    '{{body}}': 'lorem ipsum dolor sit amet',
})

print(template)