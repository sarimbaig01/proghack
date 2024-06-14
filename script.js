function copyCode() {
    const button = document.querySelector('.copy-btn');
    const originalText = button.textContent;
    const code = document.getElementById('cpp-code').textContent.trim();
    
    navigator.clipboard.writeText(code).then(function() {
        button.textContent = '✓ Copied';
        setTimeout(function() {
            button.textContent = originalText;
        }, 3000);
    }, function(err) {
        console.error('Failed to copy: ', err);
    });
}
