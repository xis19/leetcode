def numUniqueEmails(emails):
    unique_emails = set()
    for email in emails:
        local_name, domain = email.split('@')
        local_name = local_name.replace('.', '').split('+')[0]
        unique_emails.add(local_name + '@' + domain)
    return len(unique_emails)
